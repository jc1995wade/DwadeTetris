#include "control.h"
#include <sys/time.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <termios.h>

extern struct termios tm_old;
extern int num,mode,color;
extern int n_num,n_mode,n_color;
extern int i_x,i_y;
extern int x,y;
extern int s_x,s_y,l_x,l_y;

int tm = 800000;
extern void eraser_shape(int,int,int,int,int);
extern int shape[7][4][18];

int p_x = 60,p_y = 15;
int matrix[24][28] = {0};
int score,level;

//微妙定时器,定时器一旦启动，会每隔一段时间发送SIGALRM信号
void alarm_us(int t)
{
	struct itimerval value;
	//定时器启动的初始值
	value.it_value.tv_sec = 0;
	value.it_value.tv_usec = t;

	//定时器启动后的间隔时间值
	value.it_interval.tv_sec = 0;
	value.it_interval.tv_usec = t;

	setitimer(ITIMER_REAL,&value,NULL);
}

//信号注册函数
void catch_signal(int signo)
{
	//向下移动图形，一直到底部
	move_shape_down(num,mode,color);
	signal(SIGALRM,catch_signal);
}

//碰撞检测,检测方块是否碰撞到边界或其他方块
int judge_shape(int n,int m,int x,int y)
{
	
}
//保存方块棋盘信息，方块落地后，需将整个方块图形进行保存
static void store_shape(int n,int m,int x,int y)
{
	
}
//初始化棋盘
static void init_shape()
{
	//当方块下落到底部时，控制区产生新的方块
	//打印下移方块
		
}
//打印棋盘
static void print_matrix()
{
	
}
//打印方块分数及等级
static void print_score_level()
{
	
}
//消行检测，当一行不满时，进行消行操作
static void destroy_line()
{
	//检测到消行	
	//分数累加
	//重新打印地图
}

extern void game_over();
//判断游戏是否结束
int is_over()
{
	
}
//图形下落函数
int move_shape_down(int n,int m,int c)
{
	//首先判断，图形有没有触底
	//保存现有图形
	//消行
	//移动后不会触底
	//先清理原有图形
	
}

static void fall_down()
{
	//直接落地
}
//方块左移
static int move_shape_left(int n,int m,int a,int b,int c)
{
	//如果越界，返回
	//检测碰撞
	

	//消除当前图形
	//左移
	//打印
	

	return 0;
}
//方块右移
static int move_shape_right(int n,int m,int a,int b,int c)
{
	//如果越界，返回
	//检测碰撞
	

	//消除当前图形
	//右移
	//打印

	return 0;
}
//方块变形
static int change_shape(int n,int m,int c)
{
	//越界返回
	//变形前先消除原图形
	//旋转
	//打印
	return 0;
}

void game_over()
{
	//固定地点打印游戏结束字样
	
}
//关闭定时器
void close_alarm()
{
	struct itimerval value;
	//定时器启动的初始值
	value.it_value.tv_sec = 0;
	value.it_value.tv_usec = 0;

	//定时器启动后的间隔时间值
	value.it_interval.tv_sec = 0;
	value.it_interval.tv_usec = 0;
	setitimer(ITIMER_REAL,&value,NULL);
}

void key_control()
{
	static int count;
	int ch;
	//q退出
	//回车直接到底
	//空格暂停
	//上 方块旋转
	//下 方块下移
	//左 方块左移
	//右 方块右移
	
}
