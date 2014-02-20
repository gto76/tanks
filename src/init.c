#include	<allegro.h>
#include	"struc.h"
#include	"konst.h"
#include	"funct.h"
#include	"var.h"
 
void tankca();
void kugle();
void kraterji();
void narisi();
void zvok();

void 
init()
{
        install_keyboard();
	install_timer();
	if (set_gfx_mode(GFX_AUTODETECT, SIRINA, VISINA, 0, 0) < 0) {
		printf("%s\n", allegro_error);
		exit(1);
	}
	//zvok();
	
	clear(screen);
	end_game=0;
	tankca();
	kugle();
	kraterji();
	narisi();	//narise ozemlje in tankca
}

void
tankca()
{
	tnk1.x=SIRINA/6;
	tnk1.dx=SIRINA/6; //leva stran
	tnk1.y=B-1;
	tnk1.dy=B-1;      //eno piko nad tlemi
	tnk1.fi=tnk1.dfi=1;	  //cev	
	tnk1.fire=tnk1.moc=0;
	tnk1.t=-1;
	
	tnk2.x=SIRINA/6*5;//desna stran
	tnk2.dx=SIRINA/6*5;
	tnk2.y=B-1;
	tnk2.dy=B-1;
	tnk2.fi=tnk2.dfi=2;
	tnk2.fire=tnk1.moc=0;
	tnk2.t=-1;
}

void
kugle()
{
	int i;
	for(i=0;i<=9;i++) 
		kgl[i].t=-1;
}

void
kraterji()
{
	int i;
	kratr[0]=SREDINA;
	for(i=1;i<=499;i++)
		kratr[i]=-1;
}		

void
narisi()
{
	//ozemlje
	line(screen,0,B,SIRINA,B,15);
	krater();
	
	//okvir za merilca
	rect(screen,10,VISINA-10,110,VISINA-20,15);
	rect(screen,SIRINA-10,VISINA-10,SIRINA-110,VISINA-20,15);

	//tankca
	tank_draw(&tnk1);
	tank_draw(&tnk2);
}

void
zvok()
{
	if (install_sound(DIGI_AUTODETECT, MIDI_NONE, NULL) != 0) {
		allegro_message("Error initialising sound system\n%s\n",
				allegro_error);
      		exit(1);
	}
	blast = load_sample("./res/blast.wav");
	cev = load_sample("./res/cev.wav");
	fire = load_sample("./res/fire.wav");
	load = load_sample("./res/load.wav");
	move = load_sample("./res/move.wav");
	themes = load_sample("./res/themes.wav");
	hit = load_sample("./res/hit.wav");
	battle = load_sample("./res/battle.wav");
}










