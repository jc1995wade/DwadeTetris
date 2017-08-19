#include <stdio.h>
#include "block_display.h"
//整体大框（包含边框）
#define Block_weight  35
#define Block_lenth   70
#define Block_frame_weight1 47
#define Block_frame_lenth1 25
//weight2  --- 左边大框（内框）
#define Block_frame_lenth2 30
void block_display_clear()
{
	int i,j;
	for(i = 0; i < Block_weight;i++)
		for(j = 0; j < Block_lenth; j++){
			printf("\033[%d;%dH\033[0m",i ,j);
			printf("\033[45m \033[0m");
		}
}

void block_display_frame()
{  //大框上
	int i;
	for(i = 0;i < Block_frame_weight1; i++ ){
		printf("\033[%d;%dH\033[0m",4 ,i+9);	
		printf("\033[34m1\033[0m");
	}
	//大框下
	for(;i>=0; i--){
		printf("\033[%d;%dH\033[0m",4+Block_frame_lenth1 ,i+9);	
		printf("\033[34m2\033[0m");
	}
	//大框左边
	for(i = 0; i <= Block_frame_lenth1; i++ ){	
		printf("\033[%d;%dH\033[0m",4+i,9);	
		printf("\033[34m34\033[0m");
	}
	//大框中间
	for(i = 0; i <= Block_frame_lenth1; i++ ){	
		printf("\033[%d;%dH\033[0m",4+i,9+Block_frame_lenth2);	
		printf("\033[34m56\033[0m");
	}
   //大框最右边	
	for(i = 0; i <= Block_frame_lenth1; i++ ){	
		printf("\033[%d;%dH\033[0m",4+i,9+Block_frame_lenth2+16);	
		printf("\033[34m78\033[0m");
	}
	printf("\033[%d;%dH\033[0m",4+7,9+Block_frame_lenth2);
	printf("\033[34m9999999999999999\033[0m");
	

	/*              　行*列         行*列        */
	/*左边内框起始坐标:4*10    大小:24*28　　　　*/
	/*右上框起始坐标  :4*41    大小:6*14         */
	/*右下框起始坐标  :11*41   大小:6*14         */
	//显示分数
	printf("\033[%d;%dH\033[0m",11+5,41+2);
	printf("\033[34m分数:  0  \033[0m");
	//显示等级
	printf("\033[%d;%dH\033[0m",11+10,41+2);
	printf("\033[34m等级:  5  \033[0m");
	
	printf("\033[%d;%dH\033[0m",Block_weight, Block_lenth);	
}


