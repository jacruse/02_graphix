#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

int main() {

  screen s;
  color c;

  c.red = 0;
  c.green = MAX_COLOR;
  c.blue = 0;

  clear_screen(s);

  //oct 1
  draw_line(0, 0, 40, 20, s, c);
  draw_line(80, 40, 40, 20, s, c);

  //oct 2
  draw_line(0, 0, 20, 40, s, c);
  draw_line(40, 80, 20, 40, s, c);

  //oct 8
  draw_line(80, 40, 120, 20, s, c);
  draw_line(160, 0, 120, 20, s, c);

  //oct 7
  draw_line(40, 80, 60, 40, s, c);
  draw_line(80, 0, 60, 40, s, c);

  //m = 1
  draw_line(0, 0, 50, 50, s, c);

  //m = -1
  draw_line(50, 50, 100, 0, s, c);

  //m = 0
  draw_line(50, 50, 100, 50, s, c);

  //m = undef
  draw_line(50, 50, 50, 100, s, c);
	    
  display(s);
  save_extension(s, "lines.png");
}
