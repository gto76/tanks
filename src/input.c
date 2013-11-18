#include	<allegro.h>
#include	"struc.h"
#include	"konst.h"
#include	"var.h"
#define FI 0.02
#define MOC 1

void kopiraj_spremenljivke();
void igralec1();
void igralec2();

void levo(struct Tank *tnk);
void desno(struct Tank *tnk);
void gor(struct Tank *tnk);
void dol(struct Tank *tnk);
void enter(struct Tank *tnk);


void 
input()		//pregleda pritisnjene tipke obeh igralcev in escape
{
	kopiraj_spremenljivke();
	igralec1();
	igralec2();
	if(key[KEY_ESC]) end_game=1;
}

void		//prekopira trenutne spremenljivke na mesto za prejsne
kopiraj_spremenljivke()
{
	tnk1.dx=tnk1.x;
	tnk1.dy=tnk1.y;
	tnk1.dfi=tnk1.fi;

	tnk2.dx=tnk2.x;
	tnk2.dy=tnk2.y;
	tnk2.dfi=tnk2.fi;
}

void		//pregleda tipke prvega igralca
igralec1()
{
	if(key[KEY_A])
		levo(&tnk1);
	if(key[KEY_D])
		desno(&tnk1);
	if(key[KEY_W])
		dol(&tnk1);
	if(key[KEY_S])
		gor(&tnk1);
	if(key[KEY_TAB])
		enter(&tnk1);	
}

void 		//pregleda tipke drugega igralca
igralec2()
{
	if(key[KEY_LEFT])
		levo(&tnk2);
	if(key[KEY_RIGHT])
		desno(&tnk2);
	if(key[KEY_UP])
		gor(&tnk2);
	if(key[KEY_DOWN])
		dol(&tnk2);
	if(key[KEY_ENTER])
		enter(&tnk2);	
}

void 		//premakne tank za eno v levo
levo(struct Tank *tnk)
{
	int i;
	if(tnk->x>0) {
		for(i=0;kratr[i]!=-1;i++) {
			if((tnk->x < kratr[i]+2*A+1) &&
			   (tnk->x > kratr[i]-A+1))
				return;
		}		   
		tnk->x--;
	}
}

void		//premakne tank za eno v desno
desno(struct Tank *tnk)
{
	int i;
	if(tnk->x<SIRINA) {
		for(i=0;kratr[i]!=-1;i++) {
			if((tnk->x < kratr[i]+A-1) &&
			   (tnk->x > kratr[i]-2*A-1))
				return;
		}		   
		tnk->x++;
	}
}

void
gor(struct Tank *tnk)
{
	if(tnk->fi > 0.14)
		tnk->fi-=FI;
}

void
dol(struct Tank *tnk)
{
	if(tnk->fi < 3)
		tnk->fi+=FI;
}
		
void
enter(struct Tank *tnk)
{
	if(tnk->t==-1) {
		tnk->fire=1;
		if(tnk->moc <= 99)
			tnk->moc+=MOC;
	}		
}
























		
