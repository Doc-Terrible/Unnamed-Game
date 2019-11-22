#pragma once
#include<allegro5/allegro.h>
#include<allegro5/allegro_image.h>
#include<allegro5/allegro_primitives.h>
#include <allegro5/keyboard.h>
#include<cmath>
#include<vector>
#include<iostream>

const double FPS = 60;
const int SCREEN_W = 1280;
const int SCREEN_H = 736;
const int playerw = 10;
const int playerh = 23;
enum life { unbreakable, breakable, dead };
enum collision {NONE,LEFT,RIGHT,TOP,BOTTEM};
const int PLATFORMr = 16;

//int Grid[40][23]{};