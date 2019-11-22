#include "Platform.h"

Platform::Platform(int X, int Y, int Breakable){
	Xpos = X;
	Ypos = Y;
}

int Platform::collision(double X, double Y, bool Distance){
	if (Distance)return sqrt(((X - Xpos) * (X - Xpos)) + ((Y - Ypos) * (Y - Ypos)));
	else if (X + playerw < Xpos + PLATFORMr || X - playerw > Xpos - PLATFORMr || Y + playerh < Ypos + PLATFORMr || Y - playerh > Ypos - PLATFORMr) {
		return NONE;
	}
	else {
		if (X + playerw > Xpos + PLATFORMr && X < Xpos - PLATFORMr && Y > Ypos + PLATFORMr && Y < Ypos - PLATFORMr) {
			std::cout << "left collision" << std::endl;
			return LEFT;
		}
		if (X > Xpos + PLATFORMr && X - playerw < Xpos - PLATFORMr && Y > Ypos + PLATFORMr && Y < Ypos - PLATFORMr) {
			std::cout << "right collision" << std::endl;
			return RIGHT;
		}
		if (X > Xpos + PLATFORMr && X < Xpos - PLATFORMr && Y + playerh > Ypos + PLATFORMr && Y < Ypos - PLATFORMr) {
			std::cout << "top collision" << std::endl;
			return TOP;
		}
		if (X > Xpos + PLATFORMr && X < Xpos - PLATFORMr && Y > Ypos + PLATFORMr && Y + playerh < Ypos - PLATFORMr) {
			std::cout << "bottem collision" << std::endl;
			return BOTTEM;
		}
	}
}

void Platform::move(){

}

void Platform::draw(){
	al_draw_filled_rectangle(Xpos + PLATFORMr, Ypos + PLATFORMr, Xpos - PLATFORMr, Ypos - PLATFORMr, al_map_rgb(0, 127, 0));
}
