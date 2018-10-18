#pragma once
#include "pch.h"
#include "Racket.h"

Racket::Racket()
{
	//Initialize the position
	rPosX = 0;
	rPosY = 0;

	//Initialize the velocity
	rVelY = (float)c.getRacketVel();
}

Racket::Racket(float x, float y)
{
	//Initialize the position
	rPosX = x;
	rPosY = y;

	//Initialize the velocity
	rVelY = (float)c.getRacketVel();
}

float Racket::getRPosX()
{
	return rPosX;
}

float Racket::getRPosY()
{
	return rPosY;
}

void Racket::handleEvent(SDL_Event& e, float timeStep)
{
	//If a key was pressed
	if (e.type == SDL_MOUSEMOTION && e.key.repeat == 0)
	{
		int x, y;
		SDL_GetMouseState(&x, &y);

		if (rPosY < 0 || y < 0)
		{
			rPosY = 0;
		}
		else if (rPosY > c.getScreenHeight() - c.getRacketHeight() || y > c.getScreenHeight())
		{
			rPosY = (float)c.getScreenHeight() - (float)c.getRacketHeight();
		}		
		else if (y < c.getScreenHeight() && y > 0)
		{
			//Adjust position
			rPosY = (float)y - c.getRacketHeight() / 2;
			//move(timeStep);
		}

	}

}

void Racket::move(float timeStep)
{

	//Move the racket up or down
	rPosY += rVelY * timeStep;

	//If the racket went too far up or down
	if (rPosY < 0)
	{
		rPosY = 0;
	}
	else if (rPosY > c.getScreenHeight() - c.getRacketHeight())
	{
		rPosY = (float)c.getScreenHeight() - (float)c.getRacketHeight();
	}

}

void Racket::moveOpponent(float timeStep, float dPosX, float dPosY)
{
	//Detect middle of the screen
	if (dPosX > c.getScreenWidth() / 2)
	{
		//rPosY = dPosY + (c.getDotHeight() / 2) - (c.getRacketHeight() / 2);
		/*move(timeStep);*/
		
		//Move the racket up or down
		if (rPosY > dPosY && rPosY > 0) {

			rPosY -= rVelY * timeStep;
		}
		else if (rPosY < 0)
		{
			//If the racket went too far up or down
			rPosY = 0;
		}
			
		
		if (rPosY < dPosY && rPosY < c.getScreenHeight() - c.getRacketHeight())
		{			
			rPosY += rVelY * timeStep;

		}
		else if (rPosY > c.getScreenHeight() - c.getRacketHeight())
		{	
			//If the racket went too far up or down
			rPosY = (float)c.getScreenHeight() - (float)c.getRacketHeight();
		}

	}

}

void Racket::render(SDL_Renderer* gRenderer)
{

	SDL_Rect racket;
	racket.x = (int)rPosX;
	racket.y = (int)rPosY;
	racket.w = c.getRacketWidth();
	racket.h = c.getRacketHeight();

	//Render racket
	SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, 255);
	SDL_RenderDrawRect(gRenderer, &racket);
	SDL_RenderFillRect(gRenderer, &racket);


	//Show the Racket
	gRacketTexture.render((int)rPosX, (int)rPosY, gRenderer);
}

void Racket::miniRender(SDL_Renderer* gRenderer)
{

	SDL_Rect racket;
	racket.x = (int)rPosX;
	racket.y = (int)rPosY;
	racket.w = c.getRacketWidth();
	racket.h = c.getMiniRacketHeight();

	//Render racket
	SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, 255);
	SDL_RenderDrawRect(gRenderer, &racket);
	SDL_RenderFillRect(gRenderer, &racket);


	//Show the Racket
	gRacketTexture.render((int)rPosX, (int)rPosY, gRenderer);
}

void Racket::free()
{
	gRacketTexture.free();
}
