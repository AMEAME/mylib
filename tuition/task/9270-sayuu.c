/* Copyright 2016 Ryuichirouh Ikeuchi. All rights reserved. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
  char *magic_number;
  int width;
  int height;
  int rgb;
  unsigned char **data;
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

  char *str = (char *)malloc(3 * sizeof(char));
  fscanf(file,"%s", str);
  pgm.magic_number = str;
  fscanf(file,"%d %d", &pgm.width, &pgm.height);
  fscanf(file,"%d", &pgm.rgb);

  pgm.data = (unsigned char **)malloc(pgm.width * pgm.height
             * sizeof(unsigned char));
  int x, y;
  for(y = 0; y < pgm.height; y++) {
    pgm.data[y] = (unsigned char *)malloc(pgm.width
                  * sizeof(unsigned char));
	  for (x = 0; x < pgm.width; x++) {
      fscanf(file, "%c", &pgm.data[y][x]);
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
      fprintf(file, "%c", pgm.data[y][x]);
    }
  }
  fclose(file);
}

pgm_t edit_pgm(pgm_t pgm) {
  unsigned char **duped = (unsigned char **)malloc(pgm.width * pgm.height
                          * sizeof(unsigned char));
  int y, x;
  for (y = 0; y < pgm.height; y++) {
    duped[y] = (unsigned char *)malloc(pgm.width * sizeof(unsigned char));
    for (x = 0; x < pgm.width; x++) {
      duped[y][x] = pgm.data[y][x];
    }
  }
  for (y = 0; y < pgm.height; y++) {
      for (x = 0; x < pgm.width; x++) {
          int x_v = pgm.width - x - 1;
          pgm.data[y][x] = duped[y][x_v];
      }
  }
  return pgm;
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
  char *input_filename = argv[1];
  char *output_filename = argv[2];

  pgm_t pgm = read_pgm(input_filename);
  pgm = edit_pgm(pgm);
  write_pgm(output_filename, pgm);
  free_pgm(pgm);

  return 0;
}
