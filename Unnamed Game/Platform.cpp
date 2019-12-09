#include "Platform.h"

Platform::Platform(int X, int Y, int Breakable){
	Xpos = X;
	Ypos = Y;
}

int Platform::collision(double X, double Y, int Distance){
	switch (Distance) {
	case LEFT:
		return Xpos - (PLATFORMr + playerw);
		break;
	case RIGHT:
		return Xpos + (PLATFORMr + playerw);
		break;
	case TOP:
		return Ypos - (PLATFORMr + playerh);
		break;
	case BOTTOM:
		return Ypos + (PLATFORMr + playerh);
		break;
	}
	if (X + playerw > Xpos - PLATFORMr && X - playerw < Xpos + PLATFORMr && Y + playerh > Ypos - PLATFORMr && Y - playerh < Ypos + PLATFORMr) {
		if (X + playerw > Xpos && X - playerw < Xpos && Y + playerh > Ypos - PLATFORMr && Y < Ypos) {
			printf("top ");
			return TOP;
		}
		if (X + playerw > Xpos - PLATFORMr && X < Xpos && Y + playerh > Ypos && Y - playerh < Ypos) {
			printf("left ");
			return LEFT;
		}
		if (X + playerw > Xpos && X - playerw < Xpos && Y > Ypos && Y - playerh < Ypos + PLATFORMr) {
			printf("bottom ");
			return BOTTOM;
		}
		if (X > Xpos && X - playerw < Xpos +PLATFORMr && Y + playerh > Ypos && Y - playerh < Ypos) {
			printf("right ");
			return RIGHT;
		}
		return NULL;
	}
	else return NONE;
}

void Platform::move(){

}

void Platform::draw(){
	al_draw_filled_rectangle(Xpos + PLATFORMr, Ypos + PLATFORMr, Xpos - PLATFORMr, Ypos - PLATFORMr, al_map_rgb(0, 127, 0));
}
