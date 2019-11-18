#include <iostream>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro.h>
#include <allegro5/keyboard.h>
using namespace std;

const double FPS = 60;
const int SCREEN_W = 1000;
const int SCREEN_H = 700;
const int playerw = 10;
const int playerh = 23;
enum KEYS { JUMP, LEFT, RIGHT };

int main() {
	al_init();
	al_init_primitives_addon();
	al_install_keyboard();
	ALLEGRO_DISPLAY* display;
	display = al_create_display(SCREEN_W, SCREEN_H);
	ALLEGRO_EVENT_QUEUE* event_queue = al_create_event_queue();
	ALLEGRO_TIMER* timer = al_create_timer(1.0 / FPS);
	al_start_timer(timer);
	double x = 350; //player x position
	double y = 350; //player y position
	double DashMarkerX = 0; //x position of marker thet shows where you will move
	double DashMarkerY = 0; //y position of marker thet shows where you will move
	double angle = 0;
	double movespeed = 4; //base move speed
	double sanicX = 0; //left right speed
	double sanicY = 0; //up down speed
	double gravity = .5;
	double time = 1;
	int dashtimer = 2; //timer for dashing
	bool keys[3] = { false,false,false };
	bool canjump = false; //if can jump
	bool jumping = false; //if jumping
	bool candash = false; //if can dash
	bool dashing = false; //if dashing left
	bool slowtime = false; 
	bool grounded = false; //if on ground
	bool redraw = true;
	bool quit = false;
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_keyboard_event_source());

	while (!quit) {
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);
		if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) break;
		/* movement */
		if (ev.type == ALLEGRO_EVENT_TIMER) {
			y += sanicY * time;
			x += sanicX * time;
			if (keys[RIGHT] && grounded && !dashing && !slowtime) sanicX = movespeed;//move right
			if (keys[LEFT] && grounded && !dashing && !slowtime) sanicX = -movespeed;//move left
			if (!keys[LEFT] && !keys[RIGHT] && grounded && sanicX != 0) {
				if (sanicX > 0)sanicX += -sanicX / 2;
				else if (sanicX < 0)sanicX += -sanicX / 2;
			}
			if (sanicY < 20 && !dashing)sanicY += gravity * time;//terminal velocity & downward movement
			if (sanicX != 0) {
				if (sanicX > 0) sanicX += -.01;
				else if (sanicX < 0) sanicX += .01;
			}
			if (slowtime) {
				if (keys[RIGHT]) angle += -.1;
				if (keys[LEFT]) angle += .1;
			}
			DashMarkerX = 50 * sin(angle) + x;
			DashMarkerY = 50 * cos(angle) + y;
			
			/* jump */
			if (keys[JUMP] && canjump && grounded) {
				sanicY = -(movespeed * 2.5);
				canjump = false;
				y -= 8;
			}
			/* dash */
			if (dashing && candash) {
				candash = false;
				if (dashing) {
					sanicX = (x - DashMarkerX) / -3;
					sanicY = (y - DashMarkerY) / -3;
					dashtimer--;
				}
				if (dashtimer <= 0) {
					dashing = false;
					dashtimer = 2;
				}
			}
			else dashing = false;
			/* slow time */
			if (slowtime && candash)time = .1;
			else time = 1;
			redraw = true;
		}
		/* starting movement when key is pressed */
		if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
			switch (ev.keyboard.keycode) {
			case ALLEGRO_KEY_SPACE:
				keys[JUMP] = true;
				break;
			case ALLEGRO_KEY_A:
				keys[LEFT] = true;
				break;
			case ALLEGRO_KEY_D:
				keys[RIGHT] = true;
				break;
			case ALLEGRO_KEY_LSHIFT:
				if (candash) slowtime = true;
				break;
			case ALLEGRO_KEY_RSHIFT:
				if (candash) dashing = true;
				break;
			}
		}
		/* stoping movement when key is relessed */
		else if (ev.type == ALLEGRO_EVENT_KEY_UP) {
			switch (ev.keyboard.keycode) {
			case ALLEGRO_KEY_SPACE:
				keys[JUMP] = false;
				break;
			case ALLEGRO_KEY_A:
				keys[LEFT] = false;
				break;
			case ALLEGRO_KEY_D:
				keys[RIGHT] = false;
				break;
			case ALLEGRO_KEY_LSHIFT:
				if (candash) dashing = true;
				slowtime = false;
				break;
			case ALLEGRO_KEY_ESCAPE:
				quit = true;
				break;
			}
		}
		/* collision */
		grounded = false;
		if (x + playerw < 500 || y + playerh < 400) {}
		else {
			if (x + playerw > 500 && y > 400) {
				x = 500 - playerw;
				if (sanicX > 0)sanicX = 0;
			}
			if (y + playerh > 400 && x > 500) {
				y = 400 - playerh;
				grounded = true;
				candash = true;
				canjump = true;
				if (sanicY > 0)sanicY = 0;
			}
		}
		if (y + playerh < 690) {}
		else {
			if (y + playerh > 690) {
				y = 690 - playerh;
				grounded = true;
				candash = true;
				canjump = true;
				if (sanicY > 0)sanicY = 0;
			}
		}
		/* draw section */
		if (redraw && al_event_queue_is_empty(event_queue)) {
			redraw = false;
			al_clear_to_color(al_map_rgb(0, 0, 0));
			if (slowtime)al_draw_circle(DashMarkerX, DashMarkerY, 5, al_map_rgb(255, 0, 0), 2);
			al_draw_filled_rectangle(x + playerw, y + playerh, x - playerw, y - playerh, al_map_rgb(255, 0, 0));
			al_draw_filled_rectangle(0, 690, SCREEN_W, SCREEN_H, al_map_rgb(0, 127, 0));
			al_draw_filled_rectangle(500, 400, SCREEN_W, SCREEN_H, al_map_rgb(0, 127, 0));
			al_flip_display();
		}
	}
	al_destroy_display(display);
}