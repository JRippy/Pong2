#pragma once

#include "LTimer.h"
#include "Config.h"
#include "LTexture.h"
#include <SDL.h>


//The dot that will move around on the screen
class Dot
{
public:
	////The dimensions of the dot
	//static const int config.getDotWidth() = 20;
	//static const int config.getDotHeight() = 20;

	////Maximum axis velocity of the dot
	//static const int DOT_VEL = 640;


	Config c;

	//Initializes the variables
	Dot();

	int getPlayer1Score();
	int getPlayer2Score();

	float getMPosX();
	float getMPosY();

	//load Media Dot
	bool loadMediaDot(SDL_Renderer* gRenderer);

	//Takes key presses and adjusts the dot's velocity
	//void handleEvent(SDL_Event& e);

	//Moves the dot
	void move(float timeStep);

	//Shows the dot on the screen
	void render(SDL_Renderer* gRenderer);

	//Reset position initial
	void resetPosition();

	//Box collision detector
	bool checkCollision(int ax, int ay);

	void free();


private:
	float mPosX, mPosY;
	float mVelX, mVelY;

	//Scene textures
	LTexture gDotTexture;

	//Players
	int player1, player2 = 0;
};