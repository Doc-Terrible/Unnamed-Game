#pragma once
#include"Globals.h"
#include<allegro5/allegro.h>
#include<allegro5/allegro_image.h>
#include<allegro5/allegro_primitives.h>
#include<cmath>
class Platform{
private:
	double Xpos;
	double Ypos;
	double Xvel;
	double Yvel;
	int alive = 0;
	ALLEGRO_BITMAP* pic;
public:
	Platform(int X, int Y, int Breakable);
	int collision(int X, int Y, bool Distance);
	void move();
	void draw();
};

