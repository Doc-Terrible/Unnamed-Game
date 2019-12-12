#include "Platform.h"

Platform::Platform(int X, int Y, int Breakable){
	Xpos = X;
	Ypos = Y;
}

int Platform::collision(double X, double Y, int Distance){
	switch (Distance) {
	case LEFT:
		return Xpos - (PLATFORMr + playerw - 1);
		break;
	case RIGHT:
		return Xpos + (PLATFORMr + playerw - 1);
		break;
	case TOP:
		return Ypos - (PLATFORMr + playerh - 1);
		break;
	case BOTTOM:
		return Ypos + (PLATFORMr + playerh - 1);
		break;
	}
	if (X + playerw > Xpos - PLATFORMr && X - playerw < Xpos + PLATFORMr && Y + playerh > Ypos - PLATFORMr && Y - playerh < Ypos + PLATFORMr) {
		//have I hit the top of the platform?
		if (X > Xpos - PLATFORMr && X < Xpos + PLATFORMr && Y + playerh > Ypos - PLATFORMr && Y < Ypos) {
			return TOP;
		}
		//have I hit left side of platform
		if (X + playerw > Xpos - PLATFORMr && X < Xpos && Y > Ypos - PLATFORMr && Y < Ypos + PLATFORMr) {
			return LEFT;
		}
		//have I hit the bottom of my platform
		if (X > Xpos - PLATFORMr && X < Xpos + PLATFORMr && Y > Ypos && Y - playerh < Ypos + PLATFORMr) {
			return BOTTOM;
		}
		//have I hit right side of platform
		if (X > Xpos && X - playerw < Xpos + PLATFORMr && Y > Ypos - PLATFORMr && Y < Ypos + PLATFORMr) {
			return RIGHT;
		}
	}
	else return NONE;
}

void Platform::move(){

}

void Platform::draw(){
	al_draw_filled_rectangle(Xpos + PLATFORMr, Ypos + PLATFORMr, Xpos - PLATFORMr, Ypos - PLATFORMr, al_map_rgb(0, 127, 0));
}
