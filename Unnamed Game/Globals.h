#pragma once
#include<allegro5/allegro.h>
#include<allegro5/allegro_image.h>
#include<allegro5/allegro_primitives.h>
#include<allegro5/keyboard.h>
#include<allegro5/allegro_font.h>
#include<allegro5/allegro_ttf.h>
#include<cmath>
#include<vector>
#include<iostream>

const double FPS = 60; //frame rate
const int SCREEN_W = 1280; //screen width
const int SCREEN_H = 736; //screen hight
const int playerw = 10; //half player width
const int playerh = 23; //helf player hight
enum life { unbreakable, breakable, dead }; //platporm braekable states
enum collision { NONE, LEFT, RIGHT, TOP, BOTTOM }; //for what collision player is hitting
const int PLATFORMr = 16; //platform width & hight