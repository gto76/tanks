#include	<math.h>
#include	<allegro.h>
#include	"struc.h"
#include	"konst.h"
#include	"var.h"

void tank_draw(struct Tank *tnk);
void tank_erase(struct Tank *tnk);
void risi(int x,int y,int b,float fi);
void granate();
void merilca();
void krater();

void 
output() //prvo zbrise stvari iz prejsnih polozajev, pol pa narise na novih
{
	vsync();
	
	tank_erase(&tnk1);
	tank_erase(&tnk2);
		
	tank_draw(&tnk1);
	tank_draw(&tnk2);

	granate();
	merilca();
}

void 
tank_erase(struct Tank *tnk) //zbrise tank
{
	risi( (int)tnk->dx, (int)tnk->dy, 0, tnk->dfi);
}

void 
tank_draw(struct Tank *tnk) //narise tank
{
	risi( (int)tnk->x, (int)tnk->y, 15, tnk->fi);
}

void 
risi(int x,int y,int b,float fi) //dobi y,x,barvo in v tej barvi narise tank
{
	line(screen,x-A,y,x+A,y,b);
	line(screen,x-2*A,y-A,x+2*A,y-A,b);
	line(screen,x-2*A,y-A,x-A,y,b);		//narise:  ____	
	line(screen,x+A,y,x+2*A,y-A,b);		//         \__/
	arc(screen,x,y-A,itofix(0),itofix(128),A,b); //kupola
	line(screen,x + A*cos(fi),y-A - A*sin(fi),
		    x + 2*A*cos(fi),y-A - 2*A*sin(fi),b); //cev
}

void
granate()
{
	int i;
	if(end_game==0) {
		for(i=0;i<=9;i++) {
			if(kgl[i].t!=-1) {
				putpixel(screen,(int)kgl[i].dx,(int)kgl[i].dy,0);
				putpixel(screen,(int)kgl[i].x,(int)kgl[i].y,15);
			}
		}
	}	
}	

void
merilca()
{
	if(tnk1.fire)
		rectfill(screen,10,VISINA-11,10+tnk1.moc,VISINA-19,15);
        else
        {
		rectfill(screen,11+( tnk1.dmoc - (tnk1.dmoc * tnk1.t / 100)),
			VISINA-11,109,VISINA-19,0);
		line(screen,110,VISINA-10,110,VISINA-20,15);	
        }
        	
	if(tnk2.fire)
		rectfill(screen,SIRINA-10,VISINA-11,SIRINA-10-tnk2.moc,
			VISINA-19,15);
	else
	{
		rectfill(screen,SIRINA-11-(tnk2.dmoc - 
			(tnk2.dmoc * tnk2.t / 100)),
			VISINA-11,SIRINA-109,VISINA-19,0);
		line(screen,SIRINA-110,VISINA-10,SIRINA-110,VISINA-20,15);
	}	
}

void
krater()
{
	int i;
	for(i=0;kratr[i]!=-1;i++) {
		arc(screen,kratr[i],B,itofix(128),itofix(256),A,15);//krater
		line(screen,kratr[i]-A,B,kratr[i]+A,B,0);
	}
	for(i=0;kratr[i]!=-1;i++) {
		circlefill(screen,kratr[i],B,A-1,0); //zapolnitev kraterja 
	}
}		

















	
