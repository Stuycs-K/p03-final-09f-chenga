#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <time.h>
#include <ctype.h>

#ifndef HANGMAN_H
#define HANGMAN_H

struct wordStruct {
  char category[50];
  char word[50];
};

struct wordStruct getWord();
int startRound();
int playGame();

#endif
