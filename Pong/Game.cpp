#include "pch.h"
#include "Game.h"
#include "config.h"


Game::Game()
{
}


Game::~Game()
{
}

bool Game::endGame(int p1, int p2)
{
	bool end = false;

	if (p1 == c.getEndPartyGameScore() || p2 == c.getEndPartyGameScore())
	{
		end = true;
	}

	return end;
}

void Game::displayWinner(int p1, int p2, SDL_Color textColor, SDL_Renderer* gRenderer)
{
	std::string winnerText = "";

	if (p1 == c.getEndPartyGameScore())
	{
		winnerText = "Player 1 Win!";
	}
	else
	{
		winnerText = "Player 2 Win!";
	}

	gInputTextTexture.loadFromRenderedText(winnerText.c_str(), textColor, gRenderer);
	gPromptTextTexture.render((c.getScreenWidth() - gPromptTextTexture.getWidth()) / 2, 0, gRenderer);
	gInputTextTexture.render((c.getScreenWidth() - gInputTextTexture.getWidth()) / 2, c.getScreenHeight() / 2, gRenderer);
	
}
