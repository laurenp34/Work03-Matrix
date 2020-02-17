#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"

int main() {

  screen s;
  color c;
  struct matrix *edges;

  edges = new_matrix(4, 4);

  // //octants 1 and 5
  c.red = 0;
  c.green = 255;
  c.blue = 0;
  add_edge(edges, 0, 0 , 1, XRES-1, YRES-1, 1);
  add_edge(edges, 0, XRES-1, 1, YRES-1, 0, 1);
  add_edge(edges, 0, 0, 1, XRES-1, YRES / 2, 1);
  add_edge(edges, XRES-1, YRES-1, 1, 0, YRES / 2, 1);
  draw_lines(edges,s,c);
  free_matrix(edges);

  //octants 8 and 4
  edges = new_matrix(4, 4);
  c.blue = 255;
  add_edge(edges, 0, YRES-1, 1, XRES-1, 0, 1);
  add_edge(edges, 0, YRES-1, 1, XRES-1, YRES/2, 1);
  add_edge(edges, XRES-1, 0, 1, 0, YRES/2, 1);
  draw_lines(edges,s,c);
  free_matrix(edges);

  //octants 2 and 6
  edges = new_matrix(4, 4);
  c.red = 255;
  c.green = 0;
  c.blue = 0;
  add_edge(edges, 0, 0, 1, XRES/2, YRES-1, 1);
  add_edge(edges, XRES-1, YRES-1, 1, XRES/2, 0, 1);
  draw_lines(edges,s,c);
  free_matrix(edges);

  //octants 7 and 3
  edges = new_matrix(4, 4);
  c.blue = 255;
  add_edge(edges, 0, YRES-1, 1, XRES/2, 0, 1);
  add_edge(edges, XRES-1, 0, 1, XRES/2, YRES-1, 1);
  draw_lines(edges,s,c);
  free_matrix(edges);

  //horizontal and vertical
  edges = new_matrix(4, 4);
  c.blue = 0;
  c.green = 255;
  add_edge(edges, 0, YRES/2, 1, XRES-1, YRES/2, 1);
  add_edge(edges, XRES/2, 0, 1, XRES/2, YRES-1, 1);
  draw_lines(edges,s,c);

  // print_matrix(edges);
  //
  // int i;
  // for (i=0;i<7;i++) {
  //   add_point(edges,i,i+1,i+2);
  // }
  // print_matrix(edges);
  //
  // ident(edges);
  // print_matrix(edges);

  draw_lines(edges,s,c);
  display(s);
  save_extension(s, "lines.png");
  save_ppm(s, "binary.ppm");
  free_matrix( edges );
}
