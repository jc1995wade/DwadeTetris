#include <stdio.h>
#include <signal.h>
#include "block_display.h"
#include "block_options.h"
#include "print.h"
#include "timer.h"
#include "check_border.h"
extern int cheng[24][15];
extern int direct_c;
extern int time_flag;
extern int now_x;
extern int now_y;
extern int n_color;
extern int n_mode;
extern int m_score;
extern int counter;
int main(int argc, char* argv[])
{
	block_display_clear();
	block_display_frame();
	print_score();
	print_level();
	print_next();

	
	signal(SIGALRM,signal_handler);
	set_timer();
	//save_now_state();
	while(1) {
	switch (getch()) {
		case 'w':
		//	if(judge_all(direct_c,now_x, now_y) == 1) break;
			if(judge_direct() == 1) break;	
		    direct_c = (direct_c+1)%4;
		    print_direct();
			save_now_state();
			break;
		case 's':
			if(1 == judge_down())
			{
				print_next();
				break;
			}
			print_move_down();	
			save_now_state();
			break;
		case 'a':
			if(now_x-5 <= 0)break;
			if(1 == judge_left()) break;
			
			print_move_left();
			save_now_state();
			break;
		case 'd':
			if(1 == judge_right()) break;
			
			print_move_right();
			save_now_state();
			break;
		default:{
				  int x,y;
					printf("\n");
					printf("\n");

					printf("now_x = %d\n",now_x);
					printf("now_y = %d\n",now_y);
					printf("dire=%d!!\n",direct_c);
					printf("cheng[0]=%d!!\n",cheng[now_x-5][(now_y-9)/2]);
					printf("cheng[1]=%d!!\n",cheng[now_x-5+1][(now_y-9)/2]);
					printf("cheng[2]=%d!!\n",cheng[now_x-5+2][(now_y-9)/2]);
					printf("cheng[3]=%d!!\n",cheng[now_x-5+3][(now_y-9)/2]);
					printf("counter=%d!!\n",counter);
					printf("m_score=%d!!\n",m_score);
				  for(x = 0; x < 25; x++){
					for(y = 0; y < 15; y++){
					  printf("%2d ",cheng[x][y]);
				    }
					printf("\n");
				  }
				}
			return 0;
			break;

	}
	sleep_milli(10);
	}

	return 0;
}
