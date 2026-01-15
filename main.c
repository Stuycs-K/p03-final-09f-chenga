#include "hangman.h"
#include "setup.h"


int main(int argc, char const *argv[]) {
  remove0();
  setup();
  update(playGame());
  printf("\nThanks for playing!\n");
  remove0();
  return 0;
}
