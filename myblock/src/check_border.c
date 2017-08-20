#include <stdio.h>
#include "check_border.h"


extern int shape[7][4][18];
extern int now_x,now_y;
extern int n_mode,direct_c;
extern int m_score;
extern int m_level;
extern int counter;
extern int n_color;
int cheng[26][15]={ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
					0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
					0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
					0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
					0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
					0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
					0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
					0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
					0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
					0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
					0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
					0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
					0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
					0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
					0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
					0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
					0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
					0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
					0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
					0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
					0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
					0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
					0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
					0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
					1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};

//方块下方碰撞检测
//now_x - 5  ,, now_y - 9转换为容器内坐标



//边界检查
int judge_all(int direct, int n_x ,int n_y)
{
	cal_coord(&n_x, &n_y);
	
	
	int *sp = shape[n_mode][direct];
	int x,y;
	for(x = 0; x < 4 - sp[17]; x++){
		for(y = 0; y < 4 - sp[16]; y++)
		{
			if(sp[x*4 + y] & cheng[n_x + x][n_y + y]){
				return 1;
			}
		}
	}
	return 0;
}
//坐标转换(将将背景坐标转换为容器坐标)
int cal_coord(int *x, int *y)
{
	*x = *x-5;
	*y = (*y - 9)/2;
}

//下边界检查
int judge_down()
{
	if( 1==judge_all(direct_c, now_x + 1, now_y)) {
		write_cheng();
		distory_line();
		return 1;
	}
	return 0;
}

//左边界检查
int judge_left()
{
	if(1 == judge_all(direct_c, now_x, now_y-2) ) {
		return 1;
	}
	return 0;
}

//右边界检查
int judge_right()
{
	if( 1 == judge_all(direct_c, now_x, now_y+2)) {
		return 1;
	}
	return 0;
}

//旋转检查
int judge_direct()
{
	int tm = direct_c < 3 ? direct_c + 1 : 0;
	if( 1 == judge_all(tm, now_x, now_y)) {
		return 1;
	}
	return 0;
}



//保存下落数据
void write_cheng()
{
	int i, j, k = 0;
	for(i = 0; i < 4; i++){
	  for(j = 0; j < 4; j++)
	  {
		if(shape[n_mode][direct_c][k++] == 1){
			cheng[ now_x-5+i ][ (now_y-9)/2+j ] = ((n_color << 1)|1);//保存颜色信息
		}
		if(now_x-5 < counter) 
			counter = now_x-5;
	  }
	}
}




//消行
void distory_line()
{
	int tm = shape[n_mode][direct_c][17]; 
	
	int i, j, k;
	int flag;
	int lines = 0;
	for(i = 0; i < 4-tm; i++ ) {
		flag = 1;
		for(j = 0; j < 15; j++) {
			if(cheng[now_x-5+i][j] == 0) {
				flag = 0;
				break;
			}
		}
		if( flag == 1) {
			m_score += 10;
			if(m_score >= 100)
			{
				m_level++;
				m_score = 0;
				print_level();
			}
			counter++;
			//消去一行
			for(j = now_x-5+i;j >= counter-1; j--) 
			{
				for(k = 0; k < 14; k++) {
					cheng[j][k] = cheng[j - 1][k];
				//擦除上一行
					printf("\033[%d;%dH\033[45m  \033[0m", j-1+5, k*2+11);
				//打印当前行
					printf("\033[%d;%dH\033[0m", j+5, k*2+11);
					if(cheng[j][k] != 0 ) {
						printf("\033[%dm[]\033[0m", (cheng[j][k]-1)/2);
					}
					else {
						printf("\033[45m  \033[0m");
					}
				}
			}
			print_score();
		}
	}

}



void print_score()
{
	printf("\033[%d;%dH\033[0m",11+5, 41+2+4);
	printf("\033[32m%3d\033[0m",m_score);
}

void print_level()
{
	printf("\033[%d;%dH\033[0m",11+5+5, 41+2+4);
	printf("\033[32m%3d\033[0m",m_level);
}


