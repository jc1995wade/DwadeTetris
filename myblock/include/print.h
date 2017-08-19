#ifndef _PRINT_H_
#define _PRINT_H_

#if 0
extern int s_x;
extern int s_y;
extern int l_x;
extern int l_y;

extern int num,mode,color;
extern int n_num,n_mode,n_color;
extern int i_x,i_y;
extern int n_x,n_y;

void print_start_interface();
int getch();

void print_next();
void eraser_shape(int,int,int,int,int);
#endif
void print_move_down();
void print_move_left();
void print_move_right();
void print_diredt();
extern void print_mode_shape(int n,int m,int sh, int direct_c,int n_color);
extern void remove_mode_shape(int n,int m,int sh, int direct_c);

void move_check_border();
void move_check_left();
void move_check_right();
int  move_check_direct();
#endif
