#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <time.h>

int err(){
    printf("errno %d\n", errno);
    printf("%s\n", strerror(errno));
    exit(1);
}

struct wordStruct {
  char category[50];
  char word[50];
};

struct wordStruct getWord(){
  int csv = open("wordBank.csv", O_RDONLY);
  if (csv == -1) err();
  struct wordStruct * wordsList = (struct wordStruct*)malloc(sizeof(struct wordStruct) * 100); //come back to this
  int wordCount = 0;
  char buffer[1];
  int pos = 0;
  char lines[256];
  while(read(csv, buffer, 1) > 0){
    if (buffer[0] == '\n'){
      if (pos == 0) continue;
      lines[pos] = '\0';
      pos = 0;

      sscanf(lines, "%s,%s", &wordsList[wordCount].category, &wordsList[wordCount].word);
      wordCount++;
    }
    else{
      lines[pos] = buffer[0];
      pos++;
    }
  }
  srand(time(NULL));
  int wordIndex = rand() % wordCount;
  //change so that when a word is chosen, it is taken out of the csv
  return wordsList[wordIndex];
}
void startRound(){
  struct wordStruct wordPair = getWord();
  printf("Category %s\n", wordPair.category);

  char word[50];
  strcpy(word, wordPair.word);

  int wordLen = strlen(word);
  char* curr = (char*)malloc(wordLen);
  for (int i = 0; i < wordLen; i++){
    curr[i] = '_';
  }
  while(strstr(curr, '_') != NULL){
    printf("%s\n", curr);
    printf("Enter Your Letter Guess: \n");
    fflush(stdout);
    char* guess;
    fgets(guess, sizeof(guess), stdin);
    while(strcasestr(word, guess[0]) != NULL){
      strcpy(curr[strcasestr(word, guess[0])], word[strcasestr(word, guess[0])]);

    }
  }

}
