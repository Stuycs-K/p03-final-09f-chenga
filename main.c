#include "hangman.h"
#include "setup.h"


int main(int argc, char const *argv[]) {
  update(playGame());
  printf("\nThanks for playing!\n");
  remove();
  return 0;
}
