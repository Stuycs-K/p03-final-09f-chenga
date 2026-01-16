#include "hangman.h"
#include "setup.h"

int main(int argc, char const *argv[]) {
  srand(time(NULL));
  printf("===========================\n");
  printf("WELCOME TO TERMINAL HANGMAN\n");
  printf("===========================\n");
  printf("RULES:\n");
  printf("-Keep playing until you lose\n");
  printf("-You have 6 strikes per round\n");
  printf("-You have 15 seconds to make a guess before a strike\n");
  printf("-Type 'hint' to use one of your 3 hints of the whole game\n");
  printf("-Type 'highscore' to view the current highscore\n");
  printf("===========================\n\n\n");

  if (argc > 1 && strcmp(argv[1], "clear") == 0){
    remove0();
    printf("Clear Data\n");
    return 0;
  }

  setup();
  update(playGame());
  printf("\nThanks for playing!\n");
  return 0;
}
