# Dev Log:

This document must be updated daily every time you finish a work session.

## Alvin Cheng

### 2026-01-06 - Repo Setup
Cloned Repo, Filled in README.md, copied over PROPOSAL.md, created branch "Alvin",
created .c and .h files, started hangman.c get random word. getWord() function

### 2026-01-07 - Updates
Added categories, changed wordbank.txt to csv, updated proposal to no longer require child processes, 3 hints throughout entire run, read from csv to wordStruct

### 2026-01-08 - startRound
getWord finished - it gets a struct of two words from the word bank, then gets a random one
to be sent to startRound. I intend to make it remove the word from the file when picked so
that no repeats will be had.
StartRound currently tells the reader the word and empty current guess and gets from stdin
also prints number of strikes left till lost
StartRound adds to main

### 2026-01-09 - h_files
hangman.h, hints.h, setup.h function prototypes, computers were really slow in class

### 2026-01-11 - testing, fix, and timer
strcasecmp to tolower comparing characters, fixed newfound checker, include ctype.h and include signal.h and include sys/wait.h, updated wordbank, 
removed & for sscanf, free malloced memory, makefile, removed newline after getword, made startRound into a helper for playGame, 
added child time bomb with fork and sigusr1


