#ifndef _BLOCK_OPTIONS_H_
#define _BLOCK_OPTIONS_H_
//定时间隔
//extern int tm;

//微妙定时器
//void alarm_us(int t);

//信号注册函数
//void chatch_signal(int signo);
//int position_now_x = 5;
//int position_now_y = 10+10;

//void timer(int sig);

void set_timer();
void signal_handler(int m);
int getch();
void save_now_state();








#endif
