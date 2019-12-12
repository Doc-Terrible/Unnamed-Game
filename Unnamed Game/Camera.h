#pragma once

#include <allegro5/allegro.h>
#include <vector>

#include "Globals.h"
		

// Forward class declarations, read about these here: http://jatinganhotra.com/blog/2012/11/25/forward-class-declaration-in-c-plus-plus/
class GameObject;
class Engine;

class Camera
{

private:
	vector<gameObject *> AllGameObjectsCopy;
	// Map-related information
	int xOff;				// The xOffset of the camera. Basically this is the X coordinate of the camera.
	int yOff;				// The yOffset of the camera. Basically this is the Y coordinate of the camera.

	int centerX;			// What the camera is centered on (but for edges of the map)
	int centerY;			// For this simple camera, these will always follow the player object.

	int mapDimX;			// This tells the camera how big the room is so it won't draw off the edge.
	int mapDimY;			// It's the X and Y dimensions of the room.

	

	//	References to objects
	ALLEGRO_BITMAP *backgroundimg;			// The camera needs to see the background it is expected to draw.
											// Right now, the code only has a static image as the background, so
											// that's what this holds. However, if you end up using an array or other
											// data structure as your map, then this would also change to be the
											// same kind of data.

	ALLEGRO_BITMAP *mock_display;			// This is going to be a bitmap that displays the entire map
											// and all of the objects in it. We'll draw here first before
											// selecting which portion of the map to actually show the player.

	ALLEGRO_BITMAP *screen_to_print;		// This is the thing we're going to return. It's basically the 
											// smaller portion of the whole mock_display the size of ScreenH and W.

	
	static Engine* CamEngine;
protected:

public:

	// Constructor 
	Camera();
	

	// Camera needs to see the player and the other gameobjects.
	vector<gameObject *>::iterator iter;
	void Init(vector<gameObject *> GameObjects);

	// Activity on a clock tic
	void Update(); // Tells the camera to adjust itself to center on player, watch for edges, etc.
	void setMapDim(int MapW, int MapH); // Camera needs to know the size of the map.


	//Render
	ALLEGRO_BITMAP* Render(); // Returns a portion of the whole map centered on player.



};