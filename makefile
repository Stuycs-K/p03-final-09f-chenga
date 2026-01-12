.PHONY: compile run clean 

compile: main

main: hangman.o setup.o hints.o main.o
	@gcc -Wall -o main hangman.o setup.o hints.o main.o

setup.o: setup.c setup.h
	@gcc -Wall -c setup.c

hints.o: hints.c hints.h
	@gcc -Wall -c hints.c

main.o: main.c
	@gcc -Wall -c main.c

hangman.o: hangman.c hangman.h
	@gcc -Wall -c hangman.c

run: main 
	@./main

clean:
	rm -f *o main
