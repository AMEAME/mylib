#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int get_pip(int enabled_init) {
  if (enabled_init) {
    srand((unsigned int)time(NULL));
  }
  return rand() % 6 + 1;
}

int main() {
  get_pip(1);
  int i;
  for (i = 0; i < 9; i++) {
    printf("%d ", get_pip(0));
  }
  return 0;
}

