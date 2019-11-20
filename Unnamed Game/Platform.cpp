#include "Platform.h"

Platform::Platform(int X, int Y, int Breakable){
	Xpos = X;
	Ypos = Y;
}

int Platform::collision(int X, int Y, bool Distance){
	if(Distance)return sqrt(((X - Xpos) * (X - Xpos)) + ((Y - Ypos) * (Y - Ypos)));
	else if (X + playerw < Xpos + PLATFORMr || X - playerw > Xpos - PLATFORMr || Y + playerh < Ypos + PLATFORMr || Y - playerh > Ypos - PLATFORMr)return NONE;
	else {
		if (X + playerw > Xpos + PLATFORMr && X < Xpos - PLATFORMr && Y > Ypos + PLATFORMr && Y < Ypos - PLATFORMr)return LEFT;
		if (X > Xpos + PLATFORMr && X - playerw < Xpos - PLATFORMr && Y > Ypos + PLATFORMr && Y < Ypos - PLATFORMr)return RIGHT;
		if (X > Xpos + PLATFORMr && X < Xpos - PLATFORMr && Y + playerh > Ypos + PLATFORMr && Y < Ypos - PLATFORMr)return TOP;
		if (X > Xpos + PLATFORMr && X < Xpos - PLATFORMr && Y > Ypos + PLATFORMr && Y + playerh < Ypos - PLATFORMr)return BOTTEM;
	}
}

void Platform::move(){

}

void Platform::draw(){
	al_draw_filled_rectangle(Xpos + PLATFORMr, Ypos + PLATFORMr, Xpos - PLATFORMr, Ypos - PLATFORMr, al_map_rgb(0, 127, 0));
}
