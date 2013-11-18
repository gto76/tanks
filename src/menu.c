#include	<stdlib.h>
#include	<allegro.h>
#include	"funct.h"
#include	"konst.h"
#include	"struc.h" 
#include	"var.h" 

void 
menu()
{
	int a=0;
	char s[50],version[]="1.0.8";

	
	play_sample(themes,255,128,1000,1);
	while(1) {
		textprintf_centre(screen,font,SREDINA,VISINA/3,15,
			"  TANKS! v%s",version);
		if(a==0) {
			textprintf_centre(screen,font,SREDINA,VISINA/3+15,
					15,"->Start game",version);
			textprintf_centre(screen,font,SREDINA,VISINA/3+30,
					15,"  Exit",version);
		}
		else {
			textprintf_centre(screen,font,SREDINA,VISINA/3+15,
					15,"  Start game",version);
			textprintf_centre(screen,font,SREDINA,VISINA/3+30,
					15,"->Exit",version);
		}
		if(key[KEY_ESC])
			exit(1);
		if(key[KEY_ENTER]) {
			if(a==0) 
				break;
			else
				exit(1);
		}
		if(key[KEY_UP]||key[KEY_DOWN]) {
			a=!a;
			rest(100);
		}			

	}
	stop_sample(themes);
	rest(200);
	clear(screen);
	narisi();
}					
			
