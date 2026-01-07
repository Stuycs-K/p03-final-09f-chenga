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
  char word[50];
  char catagory[];
}

void getWord(){
  int wordCount = 0;
  char words[256];
  int r_file = open("wordBank.txt", O_RDONLY, 0);
  if (r_file == -1) err();

  char buffer[1];
  int pos = 0;
  while(read(r_file, buffer, 1) > 0){
    if (buffer[0] == '\n')
  }

  srand(time(NULL));
  int wordNum = rand() % wordCount;
}
void startGame(){

}
