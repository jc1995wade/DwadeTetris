#ifndef _CHECK_BORDER_H_
#define _CHECK_BORDER_H_

int detection_down();
int detection_right();
int detection_left();
void write_cheng();


int judge_all(int direct, int n_x, int n_y);
int judge_down();
int judge_left();
int judge_right();
int judge_direct();
int cal_coord(int *x, int *y);
#endif
