#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <time.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/types.h>

#ifndef SETUP_H
#define SETUP_H

#define KEY 207940560
union semun {
int val;
};

void err();
void setup();
void update(int newScore);
void view();
void remove();

#endif
