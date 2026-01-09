#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <time.h>

#ifndef HANGMAN_H
#define HANGMAN_H

struct wordStruct {
  char category[50];
  char word[50];
};

int err();
struct wordStruct getWord();
void startRound();
