# Dev Log:

This document must be updated daily every time you finish a work session.

## Alvin Cheng

### 2025-01-06 - Repo Setup
Cloned Repo, Filled in README.md, copied over PROPOSAL.md, created branch "Alvin",
created .c and .h files, started hangman.c get random word. getWord() function

### 2025-01-07 - Updates
Added categories, changed wordbank.txt to csv, updated proposal to no longer require child processes, 3 hints throughout entire run, read from csv to wordStruct

### 2025-01-08 - startRound
getWord finished - it gets a struct of two words from the word bank, then gets a random one
to be sent to startRound. I intend to make it remove the word from the file when picked so
that no repeats will be had.
StartRound currently tells the reader the word and empty current guess and gets from stdin
also prints number of strikes left till lost
StartRound adds to main
