#include "hangman.h"
#include "setup.h"


int main(int argc, char const *argv[]) {
  srand(time(NULL));
  setup();
  update(playGame());
  printf("\nThanks for playing!\n");
  //remove0();
  return 0;
}
