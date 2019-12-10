#include "Platform.h"
using namespace std;

enum KEYS { KEY_LEFT, KEY_RIGHT, KEY_DOWN };

int Grid[23][40]{
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,
	1,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1
};

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
	double y = 600; //player y position
	double DashMarkerX = 0; //x position of marker thet shows where you will move
	double DashMarkerY = 0; //y position of marker thet shows where you will move
	double angle = 0;
	double movespeed = 1; //base move speed
	double sanicX = 0; //left right speed
	double sanicY = 0; //up down speed
	double gravity = .5; //gravity
	double time = 1; //for making all movment slow down
	int dashtimer = 2; //timer for dashing
	int walltimer = 10; //timer for not sliding down wall
	bool keys[3] = { false,false,false };
	bool canjump = false; //if can jump
	bool jumping = false; //if jumping
	bool candash = false; //if can dash
	bool dashing = false; //if dashing left
	bool slowtime = false; //if time is slowed
	bool grounded = false; //if on ground
	int walled = false; //if on wall
	bool redraw = true;
	bool quit = false;
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_keyboard_event_source());

	vector<Platform*> ground;
	vector<Platform*>::iterator iter;
	for (int i = 0; i < 23; i++) {
		for (int j = 0; j < 40; j++) {
			if (Grid[i][j] == 1) {
				Platform* newplatform = new Platform((j * 32) + PLATFORMr, (i * 32) + PLATFORMr, unbreakable);
				ground.push_back(newplatform);
			}
		}
	}

	while (!quit) {
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);
		if (ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) break;
		
		if (y >= SCREEN_H + playerh || y <= -playerh || x >= SCREEN_W + playerw || x <= -playerw) {
			y = SCREEN_H / 2;
			x = SCREEN_W / 2;
		}

		/* movement */
		if (ev.type == ALLEGRO_EVENT_TIMER) {
			y += sanicY * time;
			x += sanicX * time;
			if (keys[KEY_RIGHT] && grounded && !dashing && !slowtime) sanicX += movespeed;//move right
			if (keys[KEY_LEFT] && grounded && !dashing && !slowtime) sanicX += -movespeed;//move left

			/* */
			if (!keys[KEY_LEFT] && !keys[KEY_RIGHT] && grounded && sanicX != 0) {
				if (sanicX > 0)sanicX += -sanicX / 4;
				else if (sanicX < 0)sanicX += -sanicX / 4;
			}
			if (!dashing && walled == 0)sanicY += gravity * time; //aply gravity
			else if (walled > 0 && walltimer == 0)sanicY += (gravity / 4) * time; //slide down wall

			/* air resistence */
			if (sanicX != 0) {
				if (sanicX > 0) sanicX += -.05;
				else if (sanicX < 0) sanicX += .05;
			}

			/* moving dash marker */
			if (slowtime) {
				if (keys[KEY_RIGHT]) angle += -.07;
				if (keys[KEY_LEFT]) angle += .07;
			}

			/* terminal velocities */
			if (sanicY > 20 && !walled)sanicY = 15;
			else if (sanicY < -20 && !walled)sanicY = -15;
			else if (sanicY > 10 && walled)sanicY = 10;
			else if (sanicY < -10 && walled)sanicY = -10;
			if (sanicX > 5 && grounded)sanicX = 5;
			else if (sanicX < -5 && grounded)sanicX = -5;
			else if (sanicX > 20)sanicX = 15;
			else if (sanicX < -20)sanicX = -15;

			/* wall stick timer */
			if (walled > 0 && walltimer > 0)walltimer--;
			else walltimer = 10;

			/* dash marker positioning */
			DashMarkerX = 50 * sin(angle) + x;
			DashMarkerY = 50 * cos(angle) + y;

			/* dash */
			if (dashing && candash && !grounded) {
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
			case ALLEGRO_KEY_W:

				/* wall jump */
				if (walled > 0) {
					if (walled == 1 && !grounded) {
						sanicY = -8;
						sanicX = -8;
						x--;
					}
					else if (walled == 2 && !grounded) {
						sanicY = -8;
						sanicX = 8;
						x++;
					}
				}

				/* jump */
				if (canjump && grounded) {
					if (walled == 1)x--;
					else if (walled == 2)x++;
					sanicY = -10;
					canjump = false;
				}

				break;
			case ALLEGRO_KEY_A:
				keys[KEY_LEFT] = true;
				break;
			case ALLEGRO_KEY_D:
				keys[KEY_RIGHT] = true;
				break;
			case ALLEGRO_KEY_RSHIFT:
				if (candash) slowtime = true;
				break;
			case ALLEGRO_KEY_LSHIFT:
				if (candash) dashing = true;
				break;
			case ALLEGRO_KEY_S:
				if (walled == 1)x--;
				else if (walled == 2)x++;
			}
		}

		/* stoping movement when key is relessed */
		else if (ev.type == ALLEGRO_EVENT_KEY_UP) {
			switch (ev.keyboard.keycode) {
			case ALLEGRO_KEY_A:
				keys[KEY_LEFT] = false;
				break;
			case ALLEGRO_KEY_D:
				keys[KEY_RIGHT] = false;
				break;
			case ALLEGRO_KEY_RSHIFT:
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
		walled = 0;
		for (iter = ground.begin(); iter != ground.end(); iter++) {
			switch ((*iter)->collision(x, y, NONE)) {
			case NONE:
				break;
			case LEFT:
				x = (*iter)->collision(x, y, LEFT);
				if (sanicX > 0)sanicX = 0;
				if (sanicY < 0)sanicY = 0;
				dashing = false;
				walled = 1;
				break;
			case RIGHT:
				x = (*iter)->collision(x, y, RIGHT);
				if (sanicX < 0)sanicX = 0;
				if (sanicY < 0)sanicY = 0;
				dashing = false;
				walled = 2;
				break;
			case TOP:
				y = (*iter)->collision(x, y, TOP);
				if (sanicY > 0)sanicY = 0;
				dashing = false;
				grounded = true;
				candash = true;
				canjump = true;
				break;
			case BOTTOM:
				y = (*iter)->collision(x, y, BOTTOM);
				if (sanicY < 0)sanicY = 0;
				dashing = false;
				break;
			}
		}

		/* draw section */
		if (redraw && al_event_queue_is_empty(event_queue)) {
			redraw = false;
			al_clear_to_color(al_map_rgb(0, 15, 0));
			for (iter = ground.begin(); iter != ground.end(); iter++) {
				(*iter)->draw();
			}
			if (slowtime)al_draw_circle(DashMarkerX, DashMarkerY, 5, al_map_rgb(255, 0, 0), 2);
			al_draw_filled_rectangle(x + playerw, y + playerh, x - playerw, y - playerh, al_map_rgb(255, 0, 0));
			al_flip_display();
		}
	}
	al_destroy_display(display);
}