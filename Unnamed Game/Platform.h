#pragma once
#include"Globals.h"
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
	int collision(double X, double Y, bool Distance);
	void move();
	void draw();
};

