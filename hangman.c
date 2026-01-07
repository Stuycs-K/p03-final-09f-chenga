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
  char catagory[50];
  char word[50];
}

void getWord(){
  int csv = open("wordBank.csv", O_RDONLY);
  if (csv == -1) err();

  int wordCount = 0;
  char buffer[1];
  int pos = 0;
  char words[256];
  while(read(csv, buffer, 1) > 0){
    if (buffer[0] == '\n'){
      if (pos == 0) continue;
    }
  }

  srand(time(NULL));
  int wordNum = rand() % wordCount;
}
void startGame(){

}
