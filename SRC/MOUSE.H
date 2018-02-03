#ifndef __MOUSE_H__
  #define __MOUSE_H__

  #include "bitmap.h"

extern volatile unsigned int mouse_x,mouse_y,mouse_b;
extern volatile unsigned int mouse_buttons;

extern BITMAP *mouse_cursor;

int install_mouse(BITMAP *mscr);
void remove_mouse();
void show_mouse();
void hide_mouse();
int detect_mouse();
void move_mouse(unsigned int x,unsigned int y);
void mouse_area(unsigned int x1,unsigned int y1,unsigned int x2,unsigned int y2);
void set_default_mouse_cursor();
void set_mouse_focus(unsigned int x,unsigned int y);
void set_mouse_cursor(BITMAP *cursor,unsigned int fx,unsigned int fy);

#endif