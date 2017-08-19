#include "check_border.h"
extern int shape[7][4][18];
extern int now_x,now_y;
extern int n_mode,direct_c;
extern int m_score;
extern int m_level;
int cheng[24][15]={ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
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

int cal_coord(int *x, int *y)
{
	*x = *x-5;
	*y = (*y - 9)/2;
}

int judge_down()
{
	if( 1==judge_all(direct_c, now_x + 1, now_y)) {
		write_cheng();
		return 1;
	}
	return 0;
}


int judge_left()
{
	if(1 == judge_all(direct_c, now_x, now_y-2) ) {
		return 1;
	}
	return 0;
}


int judge_right()
{
	if( 1 == judge_all(direct_c, now_x, now_y+2)) {
		return 1;
	}
	return 0;
}


int judge_direct()
{
	int tm = direct_c < 3 ? direct_c + 1 : 0;
	if( 1 == judge_all(tm, now_x, now_y)) {
		return 1;
	}
	return 0;
}



void write_cheng()
{
	int i, j, k = 0;
	for(i = 0; i < 4; i++){
	  for(j = 0; j < 4; j++)
	  {
		if(shape[n_mode][direct_c][k++] == 1){
			cheng[ now_x-5+i ][ (now_y-9)/2+j ] = 1;
		}
	  }
	}
}
	
