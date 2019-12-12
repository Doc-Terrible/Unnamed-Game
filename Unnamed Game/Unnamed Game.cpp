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
	double walltimer = 10; //timer for not sliding down wall
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
		
		if (y >= SCREEN_H + playerh || y <= -playerh || x >= SCREEN_W + playerw || x <= -playerw) { //if player is off screen
			y = SCREEN_H / 2; //set player y to center of screen
			x = SCREEN_W / 2; //set player x to center of screen
		}

		/* movement */
		if (ev.type == ALLEGRO_EVENT_TIMER) {
			y += sanicY * time; //slows down player x velosity when time is slowed
			x += sanicX * time; //slows down player y velosity when time is slowed
			if (keys[KEY_RIGHT] && grounded && !dashing && !slowtime) sanicX += movespeed;//move right
			if (keys[KEY_LEFT] && grounded && !dashing && !slowtime) sanicX += -movespeed;//move left

			/* alpy friction when player is on ground & isn't trying to move */
			if (!keys[KEY_LEFT] && !keys[KEY_RIGHT] && grounded && sanicX != 0) {
				if (sanicX != 0)sanicX += -sanicX / 4 * time;
			}

			/* air resistence */
			if (sanicX != 0) {
				if (sanicX > 0) sanicX += -.05 * time;
				else if (sanicX < 0) sanicX += .05 * time;
			}

			/* ably gravity */
			if (!dashing && walled == 0)sanicY += gravity * time; //normal gravity
			else if (walled > 0 && walltimer == 0)sanicY += (gravity / 4) * time; //all wall gravity

			/* moving dash marker */
			if (slowtime) {
				if (keys[KEY_RIGHT]) angle += -.07;
				if (keys[KEY_LEFT]) angle += .07;
			}

			/* terminal velocities */
			if (sanicY != 0) {
				if (sanicY > 20 && !walled)sanicY = 15; //normal down terminal velocitie
				else if (sanicY < -20 && !walled)sanicY = -15; //normal up terminal velocitie
				else if (sanicY > 10 && walled)sanicY = 7; //on wall down terminal velocitie
				else if (sanicY < -10 && walled)sanicY = -7; //on wall up terminal velocitie
			}
			if (sanicX != 0) {
				if (sanicX > 5 && grounded)sanicX = 5; //on ground left terminal velocitie
				else if (sanicX < -5 && grounded)sanicX = -5; //on ground right terminal velocitie
				else if (sanicX > 20)sanicX = 15; //in air left terminal velocitie
				else if (sanicX < -20)sanicX = -15; //in air right terminal velocitie
			}

			/* wall stick timer */
			if (walled > 0 && walltimer > 0)walltimer -= 1 * time; //reduse timer when on wall
			else walltimer = 10; //reset timer

			/* dash marker positioning */
			DashMarkerX = 50 * sin(angle) + x;
			DashMarkerY = 50 * cos(angle) + y;

			/* dash */
			if (dashing && candash && !grounded) {
				candash = false;
				if (dashing) {
					sanicX = (x - DashMarkerX) / -3; //x velocity to move player in direction of dash marker 
					sanicY = (y - DashMarkerY) / -3; //y velocity to move player in direction of dash marker 
					dashtimer--; // reduse dash timer
				}
				if (dashtimer <= 0) {
					dashing = false; 
					dashtimer = 2; //reset dash timer
				}
			}
			else dashing = false;

			/* slow time */
			if (slowtime && candash)time = .1; //slow time
			else time = 1; //reset time

			redraw = true;
		}

		/* when key is pressed */
		if (ev.type == ALLEGRO_EVENT_KEY_DOWN) {
			switch (ev.keyboard.keycode) {
			case ALLEGRO_KEY_SPACE:
			case ALLEGRO_KEY_W:

				/* wall jump */
				if (walled > 0) { //if on a wall
					if (walled == 1 && !grounded) { //if on right wall
						sanicY = -8; //set player up velocitie
						sanicX = -8; //set player left velocitie
						x--; //move player 1 pixle to the left so they don't get stuck
					}
					else if (walled == 2 && !grounded) { //if on left wall
						sanicY = -8; //set player up velocitie
						sanicX = 8; //set player right velocitie
						x++; //move player 1 pixle to the right so they don't get stuck
					}
				}

				/* jump */
				if (canjump && grounded) { //if on ground
					if (walled == 1)x--; //if against right wall move player 1 pixle to the right so they don't get stuck
					else if (walled == 2)x++; //if against left wall move player 1 pixle to the right so they don't get stuck
					sanicY = -10; //set player up velocitie
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
				slowtime = true;
				break;
			case ALLEGRO_KEY_LSHIFT:
				if (candash) {
					dashing = true;
				}
				break;
			case ALLEGRO_KEY_S:
				if (walled == 1)x--;
				else if (walled == 2)x++;
			}
		}

		/* when key is relessed */
		else if (ev.type == ALLEGRO_EVENT_KEY_UP) {
			switch (ev.keyboard.keycode) {
			case ALLEGRO_KEY_A:
				keys[KEY_LEFT] = false;
				break;
			case ALLEGRO_KEY_D:
				keys[KEY_RIGHT] = false;
				break;
			case ALLEGRO_KEY_RSHIFT:
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
				x = (*iter)->collision(x, y, LEFT); //moves player out of plaform
				if (sanicX > 0)sanicX = 0; //stops right velocitie
				if (sanicY < 0)sanicY = 0; //stops up velocitie
				dashing = false; //stops dashing
				walled = 1; //sets walled so it can be used to tell what wall you're on
				break;
			case RIGHT:
				x = (*iter)->collision(x, y, RIGHT); //moves player out of plaform
				if (sanicX < 0)sanicX = 0; //stops left velocitie
				if (sanicY < 0)sanicY = 0; //stops up velocitie
				dashing = false; //stops dashing
				walled = 2; //sets walled so it can be used to tell what wall player is on
				break;
			case TOP:
				y = (*iter)->collision(x, y, TOP); //moves player out of plaform
				if (sanicY > 0)sanicY = 0; //stops down velocitie
				dashing = false; //stops dashing
				grounded = true; //sets grounded to tell if player is on ground
				candash = true; //refreshes dash
				canjump = true; //refreshed jump
				break;
			case BOTTOM:
				y = (*iter)->collision(x, y, BOTTOM); //moves player out of plaform
				if (sanicY < 0)sanicY = 0; //stops up velocitie
				dashing = false; //stops dashing
				break;
			}
		}

		/* draw section */
		if (redraw && al_event_queue_is_empty(event_queue)) {
			redraw = false;
			al_clear_to_color(al_map_rgb(0, 15, 0));
			for (iter = ground.begin(); iter != ground.end(); iter++) {
				(*iter)->draw(); //draw platform
			}
			if (slowtime)al_draw_circle(DashMarkerX, DashMarkerY, 5, al_map_rgb(255 * !candash, 0, 255 * candash), 2); //draw dash marker when changing dash angle
			if (!slowtime)al_draw_filled_circle(DashMarkerX, DashMarkerY, 4, al_map_rgb(255 * !candash, 0, 255 * candash)); //draw dash maker when not changing dash angle
			al_draw_filled_rectangle(x + playerw, y + playerh, x - playerw, y - playerh, al_map_rgb(255, 100, 0)); //draw player
			al_flip_display();
		}
	}
	al_destroy_display(display);
}