#include "Camera.h"

//constructor
Camera::Camera(){}


void Camera::Init(vector<gameObject *> GameObjects) {
	// Map-related information
	xOff = 0;
	yOff = 0;
	centerX = 0;
	centerY = 0;
	AllGameObjectsCopy = GameObjects;

	// Set up allegro bitmaps 
	backgroundimg = al_load_bitmap("fuji.jpg");
	mock_display = NULL; // Not built yet, and size is unknown. Will vary based on map.
	screen_to_print = al_create_bitmap(SCREEN_W, SCREEN_H); // This size is known; it's the size of your window.

}


// This function gets called every time main tics the game clock.
// It will update the camera to the correct location
void Camera::Update()
{
	int frameX = 0;
	int frameY = 0;
	
	for (iter = AllGameObjectsCopy.begin(); iter != AllGameObjectsCopy.end(); iter++) {

		if ((*iter)->getID() == PLAYER) {
			centerX = (*iter)->getX();
			centerY = (*iter)->getY();
		}

	}
	// Use the centerX and centerY to figure out a new ideal location for the frame.
	frameX = centerX - (SCREEN_W / 2);
	frameY = centerY - (SCREEN_H / 2);

	// Make sure it's not displaying off of the map.
	// Correct if it is.
	if (frameX < 0) frameX = 0;
	if (frameX + SCREEN_W > mapDimX)
		frameX = mapDimX - SCREEN_W;

	if (frameY < 0) frameY = 0;
	if (frameY + SCREEN_H > mapDimY)
		frameY = mapDimY - SCREEN_H;

	// Update the xOff and yOff depending on where we ended up.
	// Assuming we got passed X and Y in absolute terms, the top left corner
	// of the map we ended up with is going to be the offsets.
	xOff = frameX;
	yOff = frameY;
}

ALLEGRO_BITMAP*  Camera::Render()
{
	// First, we will draw the entire map full of sprites to a mock bitmap.
	// Then, we will draw the section that the camera can see.
	// Might need to add functions to re-size the mock_display.
	
	al_set_target_bitmap(mock_display); 
	al_clear_to_color(al_map_rgb(0, 0, 0));


	// Draw the map
	al_draw_bitmap(backgroundimg, 0, 0, NULL);// the mock_display to match size of backgroundimg.


	// Draw gameobjects on the map
	for (iter = AllGameObjectsCopy.begin(); iter != AllGameObjectsCopy.end(); iter++) {
		(*iter)->draw();
	}
	
	// Adjust game camera to proper location and size
	al_set_target_bitmap(screen_to_print);

	//this is where the magic happens: draw this section of the world map and all the stuff on it to the screen
	al_draw_scaled_bitmap(mock_display,
		xOff, yOff,							// source origin
		SCREEN_W, SCREEN_H,					// source dimensions
		0, 0,								// target origin
		SCREEN_W, SCREEN_H,					// target dimensions
		0									// flags
	);
	return screen_to_print;
}

void Camera::setMapDim(int mapW, int mapH)
{
	mapDimX = mapW;
	mapDimY = mapH;
	// When you set a new map, it will destroy old mock display and make a new one of the right size.
	al_destroy_bitmap(mock_display);
	mock_display = al_create_bitmap(mapDimX, mapDimY);
}
