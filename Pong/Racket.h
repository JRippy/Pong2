#pragma once

#include "LTimer.h"
#include "Config.h"
#include "LTexture.h"
#include <SDL.h>

class Racket
{
public:

	/*
	NOTE

	Je prefererais une sous classe pour l'IA
	*/

	Config c;

	Racket();
	Racket(float x, float y);

	float getRPosX();
	float getRPosY();

	//Takes key presses and adjusts the racket's velocity
	void handleEvent(SDL_Event& e, float timeStep);

	//Moves the racket
	void move(float timeStep);

	//Moves the racket
	void moveOpponent(float timeStep, float dotX, float dotY);

	//Shows the racket on the screen
	void render(SDL_Renderer* gRenderer);

	void miniRender(SDL_Renderer* gRenderer);	

	void free();

private:
	float rPosX, rPosY; // remplacer par sdl_rect
	float rVelX, rVelY;

	//Texture
	LTexture gRacketTexture;
};