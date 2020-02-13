#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"

int main() {

  screen s;
  struct matrix *edges;

  edges = new_matrix(4, 4);
  edges->m[0][0] = 0;
  edges->m[1][2] = 1347;
  edges->m[1][3] = 3;
  edges->lastcol = 4;
  print_matrix(edges);
  ident(edges);
  print_matrix(edges);

  free_matrix( edges );
}