/* Copyright 2016 Ryuichirouh Ikeuchi. All rights reserved. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
  char *magic_number;
  int width;
  int height;
  int rgb;
  unsigned int **data;
} pgm_t;

FILE *open_file(FILE *file, char *file_name, char *mode) {
  if((file = fopen(file_name, mode)) == NULL) {
		perror(file_name);
    exit(EXIT_FAILURE);
	}
  return file;
}

pgm_t read_pgm(char *file_name) {
  pgm_t pgm;
  FILE *file = NULL;
  file = open_file(file, file_name, "r");

  char *str = (char *)malloc(1000 * sizeof(char));
  fscanf(file,"%s", str);
  pgm.magic_number = str;
  fscanf(file,"%d %d", &pgm.width, &pgm.height);
  fscanf(file,"%d", &pgm.rgb);

  pgm.data = (unsigned int **)malloc(pgm.width * pgm.height
             * sizeof(unsigned int));
  int x, y;
  for(y = 0; y < pgm.height; y++) {
    pgm.data[y] = (unsigned int *)malloc(pgm.width
                  * sizeof(unsigned int));
	  for (x = 0; x < pgm.width; x++) {
      fscanf(file, "%d ", &pgm.data[y][x]);
	  }
  }
  fclose(file);
  return pgm;
}

void write_pgm(char *file_name, pgm_t pgm) {
  FILE* file = NULL;
  file = open_file(file, file_name, "w");
  fprintf(file,"%s\n%d %d\n%d\n", pgm.magic_number, pgm.width,
          pgm.height, pgm.rgb);

  int x, y;
  for (y = 0; y < pgm.height; y++) {
    for (x = 0; x < pgm.width; x++) {
      fprintf(file, "%d ", pgm.data[y][x]);
    }
  }
  fclose(file);
}

pgm_t edit_pgm(pgm_t pgm1, pgm_t pgm2) {
  unsigned int output_pgm_width = pgm1.width + pgm2.width;
  unsigned int output_pgm_height = pgm1.height + pgm2.height;
  int x, y;
  pgm1.data = (unsigned int **)realloc(pgm1.data, output_pgm_width * output_pgm_height
              * sizeof(unsigned int));
  for (y = 0; y < output_pgm_height; y++) {
    pgm1.data[y] = (unsigned int *)realloc(pgm1.data[y], output_pgm_width * sizeof(unsigned int));
    for (x = 0; x < output_pgm_width; x++) {
      if (pgm1.height <= y && pgm1.width <= x) {
        pgm1.data[y][x] = pgm2.data[y - pgm1.height][x - pgm1.height];
      } else if (pgm1.height <= y && pgm1.width > x) {
        pgm1.data[y][x] = 0;
      } else if (pgm1.height > y && pgm1.width <= x) {
        pgm1.data[y][x] = pgm1.rgb;
      }
    }
  }
  pgm1.width = output_pgm_width;
  pgm1.height = output_pgm_height;
  return pgm1;
}

void free_pgm(pgm_t pgm) {
  free(pgm.magic_number);
  int i;
  for (i = 0; i < pgm.height; i++) {
    free(pgm.data[i]);
  }
  free(pgm.data);
}

int main(int argc, char **argv) {
  char *input_filename1 = argv[1];
  char *input_filename2 = argv[2];
  char *output_filename = argv[3];

  pgm_t pgm1 = read_pgm(input_filename1);
  pgm_t pgm2 = read_pgm(input_filename2);
  pgm1 = edit_pgm(pgm1, pgm2);
  write_pgm(output_filename, pgm1);
  free_pgm(pgm1);

  return 0;
}