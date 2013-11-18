#include <allegro.h>
#include "funct.h"
#include "struc.h"

int end_game;
struct Tank tnk1,tnk2;
struct Kugla kgl[10];
int kratr[500];
SAMPLE *blast;
SAMPLE *cev;
SAMPLE *fire;
SAMPLE *load;
SAMPLE *move;
SAMPLE *themes;
SAMPLE *hit;
SAMPLE *battle;
	
int main(void)
{
        allegro_init();
      
        while(1) {
	        init();
	        menu();
		/*play_sample(battle,100,128,1000,1);*/
		do{
			input();
			process();
			output();
		}
		while(end_game==0);
		/*stop_sample(battle);*/
		rest(4000);
        }
	return 0;
}
END_OF_MAIN();

