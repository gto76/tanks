struct Tank {
        float x;
        float y;    //pozicija
        float dx;
        float dy;   //pozicija na prejsnem framu
        float fi;   //naklon cevi
        float dfi;
        
	int   fire;//pritisnen space
	float moc;	
	float dmoc;        

	int t;    //cas za reloadanje
};

struct Kugla {
	float x;
	float y;
	float dx;
	float dy;
	float xzac;
	float yzac;
	
	float   vx;
	float	vy;
	float   t;
};
