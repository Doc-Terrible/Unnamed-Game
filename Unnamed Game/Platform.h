#pragma once
#include"Globals.h"
class Platform{
private:
	double Xpos; //platform x position
	double Ypos; //platform y position
	double Xvel; //platform x velocity
	double Yvel; //platform y velocity
	int alive = 0; //if platform is braekable / broken
	ALLEGRO_BITMAP* pic; //platform texture
public:
	Platform(int X, int Y, int Breakable);
	int collision(double X, double Y, int Distance);
	void move();
	void draw();
};

