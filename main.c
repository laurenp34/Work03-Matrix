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

  //DRAWING

  // // //octants 1 and 5
  // c.red = 0;
  // c.green = 255;
  // c.blue = 0;
  // add_edge(edges, 0, 0 , 1, XRES-1, YRES-1, 1);
  // add_edge(edges, 0, XRES-1, 1, YRES-1, 0, 1);
  // add_edge(edges, 0, 0, 1, XRES-1, YRES / 2, 1);
  // add_edge(edges, XRES-1, YRES-1, 1, 0, YRES / 2, 1);
  // draw_lines(edges,s,c);
  // free_matrix(edges);
  //
  // //octants 8 and 4
  // edges = new_matrix(4, 4);
  // c.blue = 255;
  // add_edge(edges, 0, YRES-1, 1, XRES-1, 0, 1);
  // add_edge(edges, 0, YRES-1, 1, XRES-1, YRES/2, 1);
  // add_edge(edges, XRES-1, 0, 1, 0, YRES/2, 1);
  // draw_lines(edges,s,c);
  // free_matrix(edges);
  //
  // //octants 2 and 6
  // edges = new_matrix(4, 4);
  // c.red = 255;
  // c.green = 0;
  // c.blue = 0;
  // add_edge(edges, 0, 0, 1, XRES/2, YRES-1, 1);
  // add_edge(edges, XRES-1, YRES-1, 1, XRES/2, 0, 1);
  // draw_lines(edges,s,c);
  // free_matrix(edges);
  //
  // //octants 7 and 3
  // edges = new_matrix(4, 4);
  // c.blue = 255;
  // add_edge(edges, 0, YRES-1, 1, XRES/2, 0, 1);
  // add_edge(edges, XRES-1, 0, 1, XRES/2, YRES-1, 1);
  // draw_lines(edges,s,c);
  // free_matrix(edges);
  //
  // //horizontal and vertical
  // edges = new_matrix(4, 4);
  // c.blue = 0;
  // c.green = 255;
  // add_edge(edges, 0, YRES/2, 1, XRES-1, YRES/2, 1);
  // add_edge(edges, XRES/2, 0, 1, XRES/2, YRES-1, 1);
  // draw_lines(edges,s,c);
  //
  // // print_matrix(edges);
  // //
  // // int i;
  // // for (i=0;i<7;i++) {
  // //   add_point(edges,i,i+1,i+2);
  // // }
  // // print_matrix(edges);
  // //
  // // ident(edges);
  // // print_matrix(edges);
  //
  // draw_lines(edges,s,c);
  // display(s);
  // save_extension(s, "lines.png");
  // save_ppm(s, "binary.ppm");
  // free_matrix( edges );

  //DRAW CAT
  int left_x = 20;
  int bot_y = 0;

  while (bot_y+100 < YRES) {

    //body
    //brown
    c.red = 139;
    c.green = 69;
    c.blue = 19;
    free_matrix(edges);
    edges = new_matrix(4, 4);
    add_edge(edges, left_x,bot_y,1,left_x+300,bot_y,1);
    add_edge(edges, left_x,bot_y,1,left_x,bot_y+100,1);
    add_edge(edges, left_x+120,bot_y,1,left_x+120,bot_y+100,1);
    add_edge(edges, left_x+120,bot_y+60,1,left_x+300,bot_y+60,1);
    add_edge(edges, left_x+300,bot_y,1,left_x+300,bot_y+60,1);
    //ears
    add_edge(edges, left_x,bot_y+100,1,left_x+20,bot_y+80,1);
    add_edge(edges, left_x+120,bot_y+100,1,left_x+100,bot_y+80,1);
    //top of head
    add_edge(edges, left_x+20,bot_y+80,1,left_x+100,bot_y+80,1);

    draw_lines(edges,s,c);
    free_matrix(edges);

    //whiskers
    c.red = 255;
    c.green = 255;
    c.blue = 255;
    edges = new_matrix(4, 4);
    add_edge(edges, left_x+85,bot_y+40,1,left_x+135,bot_y+40,1);
    add_edge(edges, left_x+90,bot_y+50,1,left_x+130,bot_y+60,1);
    add_edge(edges, left_x+90,bot_y+30,1,left_x+130,bot_y+20,1);
    add_edge(edges, left_x-15,bot_y+40,1,left_x+35,bot_y+40,1);
    add_edge(edges, left_x-10,bot_y+60,1,left_x+30,bot_y+50,1);
    add_edge(edges, left_x-10,bot_y+20,1,left_x+30,bot_y+30,1);

    draw_lines(edges,s,c);
    free_matrix(edges);

    //eyes
    //sky blue
    c.red = 135;
    c.green = 206;
    c.blue = 250;
    edges = new_matrix(4, 4);
    add_edge(edges, left_x+25,bot_y+65,1,left_x+35,bot_y+65,1);
    add_edge(edges, left_x+85,bot_y+65,1,left_x+95,bot_y+65,1);

    draw_lines(edges,s,c);

    bot_y+= 110;
  }
  display(s);
  save_extension(s, "lines.png");
  save_ppm(s, "binary.ppm");
  free_matrix( edges );

  //MATRIX OPERATIONS
  struct matrix * idt;
  struct matrix * mat;
  idt = new_matrix(4,4);
  print_matrix(idt);
  ident(idt);
  print_matrix(idt);
  idt->m[1][1] = 3;
  idt->m[2][2] = 4;

  mat = new_matrix(4,5);
  add_point(mat,1,2,3);
  add_point(mat,4,5,6);
  add_point(mat,7,8,9);
  add_point(mat,1,2,3);
  add_point(mat,10,11,12);

  printf("MULTIPLYING:\n");
  print_matrix(idt);
  printf("x\n");
  print_matrix(mat);

  matrix_mult(idt,mat);
  printf("RESULT:\n");
  print_matrix(mat);
}
