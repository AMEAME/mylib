#include <stdio.h>
#include <string.h>
#include <math.h>

int atoi(char *str) {
  int i, num = 0;
  int len = strlen(str);
  for (i = 0; i < len; i++) {
    num += (str[i] - '0') * pow(10, len - i - 1);
  }
  return num;
}

int main(int argc, char **argv) {
  if (argc != 11) {
    return 1;
  }

  int arr[10];
  int i, j;

  for (i = 0; i < 10; i++) {
    arr[i] = atoi(argv[i + 1]);
  }

 for (i = 0; i < 10; i++) {
    for (j = 0; j < 10; j++) {
      if (arr[i] < arr[j]) {
        int swp = arr[i];
        arr[i] = arr[j];
        arr[j] = swp;
      }
    }
  }

  for (i = 0; i < 10; i++) {
    printf("%d\n", arr[i]);
  }
  return 0;
}
