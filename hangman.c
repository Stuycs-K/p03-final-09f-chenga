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

void getWord(){
  int wordCount = 0;
  int r_file = open("wordBank.txt", O_RDONLY, 0);
  if (r_file == -1) err();

  int rbytes = read(r_file, )

  srand(time(NULL));
  int wordNum = rand() % wordCount;
}
void startGame(){

}
