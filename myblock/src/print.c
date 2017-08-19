#include "print.h"
#include <stdio.h>
#include <termios.h>
#include <stdlib.h>
extern int befor_direct_c;//上一次方向
extern int direct_c;//当前方向值0 1 2 3 
extern int befor_x,befor_y;
extern int now_x,now_y;//当前方块坐标
int n_num,n_mode,n_color;//
//shape[][][16]:距离 右侧空格项  [17]:距离 下方空格项
int shape[7][4][18] = 
	{
		{
			{1,1,0,0, 1,1,0,0, 0,0,0,0, 0,0,0,0, 2,2},
			{1,1,0,0, 1,1,0,0, 0,0,0,0, 0,0,0,0, 2,2},
			{1,1,0,0, 1,1,0,0, 0,0,0,0, 0,0,0,0, 2,2},
			{1,1,0,0, 1,1,0,0, 0,0,0,0, 0,0,0,0, 2,2},
		},
		{
			{1,0,0,0, 1,0,0,0, 1,0,0,0, 1,0,0,0, 3,0},
			{1,1,1,1, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,3},
			{1,0,0,0, 1,0,0,0, 1,0,0,0, 1,0,0,0, 3,0},
			{1,1,1,1, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,3},
		},
		{
			{0,1,0,0, 1,1,1,0, 0,0,0,0, 0,0,0,0, 1,2},
			{1,0,0,0, 1,1,0,0, 1,0,0,0, 0,0,0,0, 2,1},
			{1,1,1,0, 0,1,0,0, 0,0,0,0, 0,0,0,0, 1,2},
			{0,1,0,0, 1,1,0,0, 0,1,0,0, 0,0,0,0, 2,1}
		},
		{
			{1,1,0,0, 0,1,1,0, 0,0,0,0, 0,0,0,0, 1,2},
			{0,1,0,0, 1,1,0,0, 1,0,0,0, 0,0,0,0, 2,1},
			{1,1,0,0, 0,1,1,0, 0,0,0,0, 0,0,0,0, 1,2},
			{0,1,0,0, 1,1,0,0, 1,0,0,0, 0,0,0,0, 2,1},
		},
		{
			{0,1,1,0, 1,1,0,0, 0,0,0,0, 0,0,0,0, 1,2},
			{1,0,0,0, 1,1,0,0, 0,1,0,0, 0,0,0,0, 2,1},
			{0,1,1,0, 1,1,0,0, 0,0,0,0, 0,0,0,0, 1,2},
			{1,0,0,0, 1,1,0,0, 0,1,0,0, 0,0,0,0, 2,1},
		},
		{
			{0,0,1,0, 1,1,1,0, 0,0,0,0, 0,0,0,0, 1,2},
			{1,0,0,0, 1,0,0,0, 1,1,0,0, 0,0,0,0, 2,1},
			{1,1,1,0, 1,0,0,0, 0,0,0,0, 0,0,0,0, 1,2},
			{1,1,0,0, 1,0,0,0, 1,0,0,0, 0,0,0,0, 2,1}
		},
		{
			{1,0,0,0, 1,1,1,0, 0,0,0,0, 0,0,0,0, 1,2},
			{1,1,0,0, 1,0,0,0, 1,0,0,0, 0,0,0,0, 2,1},
			{1,1,1,0, 0,0,1,0, 0,0,0,0, 0,0,0,0, 1,2},
			{0,1,0,0, 0,1,0,0, 1,1,0,0, 0,0,0,0, 2,1}},
	};

//指定位置，输出图形  n　m位置　　　sh形状    方向
void print_mode_shape(int n,int m,int sh,int direct_x, int n_color)
{//指定位置输出方块
	//n ,m 方块坐标
	printf("[\033%d;%dH\033[0m", n, m );
	int i ,j;
	int k = 0;
	for(i = 0; i < 4; i++)
	{
		for(j = 0; j < 4; j++ )
		{
			if(shape[sh][direct_x][k++]==1){
				printf("\033[%d;%dH\033[0m", n+i, m+2*j+2 );
				printf("\033[%dm[]\033[0m",n_color);
			}
			
		}
	}
	printf("\033[%d;%dH\033[0m",35, 70);
}

//删除指定位置方块
void remove_mode_shape(int n,int m,int sh,int direct_x)
{
	//n ,m 方块坐标
	printf("[\033%d;%dH\033[0m", n, m );
	int i ,j;
	int k = 0;
	for(i = 0; i < 4 ; i++)
	{
		for(j = 0; j < 4; j++ )
		{
			if(shape[sh][direct_x][k++]==1){
				printf("\033[%d;%dH\033[0m", n+i, m+2*j+2 );
				printf("\033[45m  \033[0m");
			}
			
		}
	}
	printf("\033[%d;%dH\033[0m",35, 70);
}

//显示下一个出来的方块
void print_next()
{//now_x,y
	static int bef_num=0,bef_mode=0,bef_color=42;
	n_num = bef_num;
	n_mode = bef_mode;
	n_color = bef_color;
	remove_mode_shape(7,44,bef_num,direct_c);
	
	bef_num = random()%7;
	bef_mode = random()%4;
	bef_color = random()%6+41;
	print_mode_shape(7,44,bef_num,direct_c, bef_color);
}

//下移动作
void print_move_down()
{
	remove_mode_shape(now_x,now_y,n_mode,befor_direct_c);
	now_x += 1;
	
	save_now_state();
//	move_check_border();
	print_mode_shape(now_x,now_y,n_mode,direct_c, n_color);

}
//方向变化显示
void print_direct()
{	
	remove_mode_shape(now_x,now_y,n_mode,befor_direct_c);
	print_mode_shape(now_x,now_y,n_mode,direct_c, n_color);
}
//左移
void print_move_left()
{
	save_now_state();
	remove_mode_shape(now_x,now_y,n_mode,direct_c);
	move_check_left();
	print_mode_shape(now_x,now_y,n_mode,direct_c, n_color);
	
}

void print_move_right()
{
	save_now_state();
	remove_mode_shape(now_x,now_y,n_mode,direct_c);
	//move_check_right();
	now_y += 2;
	print_mode_shape(now_x,now_y,n_mode,direct_c, n_color);
	
}


/* 　边缘检测　*/

//下边缘
void move_check_border()
{
	if(now_x < 5+24-shape[n_mode][direct_c][17]-1){
		now_x += 1;	
	}
}

//左边缘
void move_check_left()
{
	if(now_y > 10 ){
		now_y -= 2;
	}
}
//右边缘
void move_check_right()
{
	if(now_y+shape[n_mode][direct_c][16] < 9+24){
		now_y += 2;
	}
}
//右边旋转检测
int move_check_direct()
{
	if(now_y+shape[n_mode][(direct_c+1)%4][16] > 9+24){
		return 0;
	}
	return 1;
		
}







