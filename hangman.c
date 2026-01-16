#include "hangman.h"
#include "setup.h"

static int timeOut = 0;
static int numHints = 3;

struct wordStruct getWord(){
  int csv = open("wordbank.csv", O_RDONLY);
  if (csv == -1) err();
  struct wordStruct * wordsList = (struct wordStruct*)malloc(sizeof(struct wordStruct) * 100);
  int wordCount = 0;
  char buffer[1];
  int pos = 0;
  char lines[256];
  while(read(csv, buffer, 1) > 0){
    if (buffer[0] == '\n'){
      if (pos == 0) continue;
      lines[pos] = '\0';
      pos = 0;

      sscanf(lines, "%49[^,],%49[^\n]", wordsList[wordCount].category, wordsList[wordCount].word);
      wordCount++;
    }
    else{
      lines[pos] = buffer[0];
      pos++;
    }
  }
  close(csv);

  int wordIndex = rand() % wordCount;
  //change so that when a word is chosen, it is taken out of the csv
  struct wordStruct chosen = wordsList[wordIndex];
  free(wordsList);
  return chosen;
}


static void sighandler(int signo){
  if (signo == SIGUSR1){
    timeOut = 1;
  }
}

int startRound(){
  signal(SIGUSR1, sighandler);

  struct wordStruct wordPair = getWord();
  char word[50];
  strcpy(word, wordPair.word);
  word[strcspn(word, "\r\n")] = '\0';
  int wordLen = strlen(word);

  char curr[wordLen+1];
  for (int i = 0; i < wordLen; i++){
    curr[i] = '_';
  }
  curr[wordLen] = '\0';
  int strikes = 6;

  while(strchr(curr, '_') != NULL && strikes > 0){
    printf("Category: %s\n", wordPair.category);
    printf("Word: %s\n", curr);
    printf("Strikes: %d\n", strikes);
    printf("Enter Your Letter Guess: \n");
    fflush(stdout);

    timeOut = 0;
    pid_t timer = fork();
    if (timer == 0){
      sleep(15);
      kill(getppid(), SIGUSR1);
      exit(0);
    }

    char guess[10];
    printf("%d\n", timeOut);

    fd_set readfd;
    FD_ZERO(&readfd);
    FD_SET(STDIN_FILENO, &readfd);
    struct timeval timeout;
    timeout.tv_sec = 15;
    timeout.tv_usec = 0;

    int s = select(STDIN_FILENO + 1, &readfd, NULL, NULL, &timeout);
    if (s <= 0 || timeOut){ // -1 for signal and 0 for timeout
      printf("Times Up! Minus one strike!\n");
      strikes--;
      kill(timer, SIGKILL);
      waitpid(timer, NULL, 0);
      continue;
    }
    //fgets(guess, sizeof(guess), stdin);
    if (FD_ISSET(STDIN_FILENO, &readfd)){
      int rbytes = read(STDIN_FILENO, guess, sizeof(guess) - 1);
      if (rbytes <= 0){
        kill(timer, SIGKILL);
        waitpid(timer, NULL, 0);
        continue;
      } 
      guess[rbytes] = '\0';
    }

    kill(timer, SIGKILL);
    waitpid(timer, NULL, 0);

    guess[strcspn(guess, "\r\n")] = '\0';
    if (strcasecmp(guess, "hint") == 0){
      if (numHints > 0){
        int hIndex = strcspn(curr, "_");
        printf("index of where the hint should be: %d\n",hIndex);
        char hChar = tolower(word[hIndex]);
        for (int i = 0; i < wordLen; i++){
          if (tolower(word[i]) == hChar) curr[i] = hChar;
        }
        numHints--;
      }
      else{
        printf("No Hints Left\n"); //slight problem: player could spam this to reset the timer
      }
      continue;
    }
    if (strcasecmp(guess, "highscore") == 0){
      view();
      continue;
    }

    int numfound = 0;
    for (int i = 0; i < wordLen; i++){
      if (tolower(word[i]) == tolower(guess[0])){
        curr[i] = word[i];
        numfound++;
      }
    }
    if(numfound == 0){
      printf("Incorrect!\n");
      strikes--;
    }
  }
  if (strikes > 0){
    printf("\nCongratulations! The word was: %s\n", word);
    return 1;
  }
  else{
    printf("\nGame Over! The word was: %s\n", word);
    return 0;
  }
}

int playGame(){
  int score = 0;
  while(1){
    if(startRound() == 0) break;
    score++;
    printf("current score: %d\n", score);
  }
  return score;
}
