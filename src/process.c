#include	<stdlib.h>
#include	<math.h>
#include	<allegro.h>
#include	"funct.h"
#include	"struc.h"
#include	"konst.h"
#include	"var.h"

#define FAKTOR 4

void sprozitev();
void spr(struct Tank *tnk,int tipka);
void inic_kugle(struct Tank *tnk);
void let();
void zadetek(int i);
void eksplozija(int i);
void zmaga(int j);
void zmg(int i,int j);
void tajmer();
void tjm(struct Tank *tnk);


void 
process()
{
	sprozitev();
	let();
	tajmer();	
}

void
sprozitev()
{
	spr(&tnk1,1);
	spr(&tnk2,0);
}			

void
spr(struct Tank *tnk,int tipka)
{
	int i;
	if((tnk->fire==1) && !( tipka?key[KEY_TAB]:key[KEY_ENTER]) ) {
		if(tnk->t==-1) { //ce je reloadnan
			play_sample(fire,255,255-(tnk->x/SIRINA*255),1000,0);
			inic_kugle(tnk);
			tnk->t=0;
			tnk->dmoc=tnk->moc; //zapomni si moc za kazanje casa
		}	
 		tnk->fire=0;
		tnk->moc=0;
	}
}

void
inic_kugle(struct Tank *tnk)
{
	int i;
	for(i=0;(kgl[i].t!=-1)&&(i<=9);i++) //poisce prazno mesto za kuglo
		;
	if(i==9) //ce ni mesta se vrne
		return;	
	kgl[i].xzac=kgl[i].x=kgl[i].dx=tnk->x + 2*A*cos(tnk->fi);
	kgl[i].yzac=kgl[i].y=kgl[i].dy=tnk->y-A - 2*A*sin(tnk->fi);
	kgl[i].vx=cos(tnk->fi)*tnk->moc;
	kgl[i].vy=sin(tnk->fi)*tnk->moc;
	kgl[i].t=0;  //jo inicializira
}

void
let()
{
	int i;
	for(i=0;i<=9;i++) {
		if(kgl[i].t!=-1) {
			kgl[i].t+=0.1;
			kgl[i].dx=kgl[i].x;
			kgl[i].dy=kgl[i].y;
			kgl[i].x=kgl[i].xzac + (kgl[i].vx*kgl[i].t);
			kgl[i].y=kgl[i].yzac - 
				 (kgl[i].vy*kgl[i].t - G*kgl[i].t
				 *kgl[i].t/2);

			if(kgl[i].y>=B-2*A)
				zadetek(i);
			//ce pade na tla
			if(kgl[i].y>=B) {
				eksplozija(i);
			//ce gre ven iz ekrana	
			if((kgl[i].x>SIRINA+A) || (kgl[i].x<-A))
				kgl[i].t=-1;
			}
		}
	}	
}

void
zadetek(int i)
{
	if((kgl[i].x<=tnk1.x) && (kgl[i].dx>tnk1.x)) {
		putpixel(screen,kgl[i].dx,kgl[i].dy,0);//zbrise zadnjo kgl			
		zmg(2,tnk1.x);
	}
	if((kgl[i].x>=tnk2.x) && (kgl[i].dx<tnk2.x)) {
		putpixel(screen,kgl[i].dx,kgl[i].dy,0);//zbrise zadnjo kgl			
		zmg(1,tnk2.x);
	}
}
		

void
eksplozija(int i)
{		
		int j;
		float fi;
		
		for(j=0;kratr[j]!=-1;j++)	//poisce mesto za krater
			;
		kratr[j]=kgl[i].x;		//kjer kgla pade je nov kratr
		putpixel(screen,kgl[i].dx,kgl[i].dy,0);//zbrise zadnjo kgl			
		zmaga(j);			//pogleda ce je kdo zmagu
		krater();			//narise vse kraterje
		play_sample(blast, 255, 255-(kgl[i].x/SIRINA*255),
			     1000, 0); 		//bummm
		kgl[i].t=-1;			//kugla se resetira
}		

void
zmaga(int j)
{
	if((tnk1.x<kratr[j]+A) && (tnk1.x>kratr[j]-A)) 
		zmg(2,kratr[j]);	  
	if((tnk2.x<kratr[j]+A) && (tnk2.x>kratr[j]-A)) 
		zmg(1,kratr[j]);
}		  

void
zmg(int i,int j)
{
	play_sample(hit,255,255-(j/SIRINA*255),1000,0);
	textprintf_centre(screen,font,SREDINA,VISINA/3,15,
			"Player %d wins!",i);
	end_game=1;
}
	
void
tajmer()
{
	tjm(&tnk1);
	tjm(&tnk2);
}
	
void
tjm(struct Tank *tnk)
{
	if(tnk->t!=-1) {
		if(tnk->t>=100) {
			play_sample(load,255,255-(tnk->x/SIRINA*255),1000,0);
			tnk->t=-1;
		}
		else
			tnk->t++;	
	}
}	














		
	








	
