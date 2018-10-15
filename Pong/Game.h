#include "LTexture.h"
#include "Config.h"

#include <string>
#include <SDL.h>
#include <SDL_image.h>
#pragma once
class Game
{
public:
	Game();
	~Game();

	bool endGame(int p1, int p2);

	void displayWinner(int p1, int p2, SDL_Color textColor, SDL_Renderer* gRenderer);

private:

	Config c;
	LTexture gPromptTextTexture;
	LTexture gInputTextTexture;

};

