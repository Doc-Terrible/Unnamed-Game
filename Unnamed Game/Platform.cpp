#include "Platform.h"

Platform::Platform(int X, int Y, int Breakable){

}

int Platform::collision(int X, int Y){
	if (X + playerw < Xpos + 16 || X - playerw > Xpos - 16 || Y + playerh < Ypos + 16 || Y - playerh > Ypos - 16)return NONE;
	else {
		if (X + playerw > Xpos + 16 && X < Xpos - 16 && Y > Ypos + 16 && Y < Ypos - 16)return LEFT;
		if (X > Xpos + 16 && X - playerw < Xpos - 16 && Y > Ypos + 16 && Y < Ypos - 16)return RIGHT;
		if (X > Xpos + 16 && X < Xpos - 16 && Y + playerh > Ypos + 16 && Y < Ypos - 16)return TOP;
		if (X > Xpos + 16 && X < Xpos - 16 && Y > Ypos + 16 && Y + playerh < Ypos - 16)return BOTTEM;
	}
}

void Platform::move(){

}

void Platform::draw(){

}
