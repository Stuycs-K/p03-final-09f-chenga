#include "hangman.h"

void err(){
    printf("errno %d\n", errno);
    printf("%s\n", strerror(errno));
    exit(1);
}

struct wordStruct getWord(){
  int csv = open("wordBank.csv", O_RDONLY);
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

      sscanf(lines, "%s,%s", wordsList[wordCount].category, wordsList[wordCount].word);
      wordCount++;
    }
    else{
      lines[pos] = buffer[0];
      pos++;
    }
  }
  close(csv);

  srand(time(NULL));
  int wordIndex = rand() % wordCount;
  //change so that when a word is chosen, it is taken out of the csv
  struct wordStruct chosen = wordsList[wordIndex];
  free(wordsList);
  return chosen;
}
void startRound(){
  struct wordStruct wordPair = getWord();
  printf("Category: %s\n", wordPair.category);
  char word[50];
  strcpy(word, wordPair.word);
  int wordLen = strlen(word);

  char curr[wordLen+1];
  for (int i = 0; i < wordLen; i++){
    curr[i] = '_';
  }
  curr[wordLen] = '\0';
  int strikes = 6;

  while(strchr(curr, '_') != NULL && strikes > 0){
    printf("Word: %s\n", curr);
    printf("Strikes: %d\n", strikes);
    printf("Enter Your Letter Guess: \n");
    fflush(stdout);
    char guess[10];
    fgets(guess, sizeof(guess), stdin);
    guess[strcspn(guess, "\n")] = '\0';

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
  }
  else{
    printf("\nGame Over! The word was: %s\n", word);
  }
}
