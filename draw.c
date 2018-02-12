#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

void swap(int * x0, int * y0, int * x1, int * y1) {
  int tx0 = *x0;
  int ty0 = *y0;

  *x0 = *x1;
  *y0 = *y1;

  *x1 = tx0;
  *y1 = ty0;
}


void oct2(int x0, int y0, int x1, int y1, screen s, color c, int a, int b) {
  int d = a + (2 * b);

  while ( y0 <= y1 ) {
    plot(s, c, x0, y0);
    if (d < 0) {
      d += (2 * a);
      x0++;
    }
    d += (2 * b);
    y0++;
  }
}

void oct1(int x0, int y0, int x1, int y1, screen s, color c, int a, int b) {
  int d = (2 * a) + b;

  while ( x0 <= x1 ) {
    plot(s, c, x0, y0);
    if (d > 0) {
      d += (2 * b);
      y0++;
    }
    d += (2 * a);
    x0++;
  }
}

void oct8(int x0, int y0, int x1, int y1, screen s, color c, int a, int b) {
  int d = (2 * a) - b;

  while ( x0 <= x1 ) {
    plot(s, c, x0, y0);
    if (d < 0) {
      d -= (2 * b);
      y0--;
    }
    d += (2 * a);
    x0++;
  }
}
  
void oct7(int x0, int y0, int x1, int y1, screen s, color c, int a, int b) {
  int d = a - (2 * b);

  while ( y0 >= y1 ) {
    plot(s, c, x0, y0);
    if (d > 0) {
      d += (2 * a);
      x0++;
    }
    d -= (2 * b);
    y0--;
  }
}
  

//Insert your line algorithm here
void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {
  if (x0 > x1) {
    swap(&x0, &y0, &x1, &y1);
  }

  int a = y1 - y0;
  int b = x0 - x1;

  if (a >= 0 && a <= -b) {
    oct1(x0, y0, x1, y1, s, c, a, b);
  }

  else if (a > 0 && a > -b) {
    oct2(x0, y0, x1, y1, s, c, a, b);
  }

  else if (a < 0 && -a <= -b) {
    oct8(x0, y0, x1, y1, s, c, a, b);
  }

  else {
    oct7(x0, y0, x1, y1, s, c, a, b);
  }
}
