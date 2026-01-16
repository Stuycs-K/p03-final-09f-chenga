.PHONY: compile run clean

compile: main

main: hangman.o setup.o main.o
	@gcc -Wall -o main hangman.o setup.o main.o

setup.o: setup.c setup.h
	@gcc -Wall -c setup.c

main.o: main.c hangman.h setup.h
	@gcc -Wall -c main.c

hangman.o: hangman.c hangman.h setup.h
	@gcc -Wall -c hangman.c

run: main
	@./main

clean:
	rm -f *o main
