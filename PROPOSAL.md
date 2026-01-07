# Final Project Proposal

## Group Members:

Alvin Cheng

# Intentions: Terminal based Hangman Game where player guesses letters to reveal the word with file handling, forking processes, semaphore/shared memory, and signal processing.

# Intended usage:

The user launches the game and receives a word from a word bank file. The user then guesses a letter, game displays word state(ie. S _ S _ _ _ S) and the # of incorrect guesses left. Separate Process can provide hints by filling in a correct letter.

# Technical Details:

A description of your technical design. This should include:

How you will be using the topics covered in class in the project.

How you are breaking down the project and who is responsible for which parts.

Files: read dictionary file with word bank, as well as a different one to store highscore. The word bank file will be a csv file with one colume being the category and the other being the word. This will be read into a struct.
Fork: child process provide hint or process player input(needs to be updated, no need for child process)
Shared Memory: allow multiple game processes to be run at the same time for highscore
Semaphore: updating shared memory one process at a time
Signals: exiting



# Intended pacing:

A timeline with expected completion dates of parts of the project.
Jan 6-7 - basic setup and file I/O
Jan 8-9 - core game logic
Jan 10-11 - fork hint process
Jan 12-13 - highscore tracking
Jan 14 - More testing/debug(edge cases etc)
Jan 15 - Video
Jan 16 - Final Fixes/fill word bank
