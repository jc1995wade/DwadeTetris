#include <stdio.h>
#include <signal.h>
#include "block_options.h"
#include "print.h"
#include <time.h>
#include <sys/time.h>
#include <stdlib.h>
#include <termios.h>
#include "check_border.h"
int time_flag = 0;
int now_x = 5;
int now_y = 9;
int befor_x = 5;
int befor_y = 9;
int befor_direct_c = 0;
int direct_c = 0;
int m_score = 0;
int m_level = 1;
int counter = 24;//指向容器内最高行数
//初始化定时器
void set_timer()
{
	struct itimerval itv;
	itv.it_value.tv_sec = 1;
	itv.it_value.tv_usec = 0;
	itv.it_interval.tv_sec = 1;
	itv.it_interval.tv_usec = 0;
	setitimer(ITIMER_REAL,&itv,NULL);
}
//定时函数
void signal_handler(int m)
{
	//下移操作	
	if(1 == judge_down()){
	  print_next();
	}
	else{
	  print_move_down();
	  printf("\n");
	}
}

// 获取键盘输入
struct termios tm_old;
int getch()
{
	struct termios tm;
	tcgetattr(0,&tm_old);
	cfmakeraw(&tm);
	tcsetattr(0,0,&tm);
	int ch = getchar();
	tcsetattr(0,0,&tm_old);

	return ch;
}

void save_now_state()
{
	befor_x = now_x;
	befor_y = now_y;
	befor_direct_c = direct_c;
}
