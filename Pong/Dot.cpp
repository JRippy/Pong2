#include "pch.h"
#include "Dot.h"


Dot::Dot()
{
	resetPosition();

	//Initialize the velocity
	mVelX = c.getDotVel();
	mVelY = c.getDotVel();
}

int Dot::getPlayer1Score()
{
	return player1;
}

int Dot::getPlayer2Score()
{
	return player2;
}

float Dot::getMPosX()
{
	return mPosX;
}

float Dot::getMPosY()
{
	return mPosY;
}

bool Dot::loadMediaDot(SDL_Renderer * gRenderer)
{
	//Loading success flag
	bool success = true;

	//Load dot texture
	if (!gDotTexture.loadFromFile("dot.bmp", gRenderer))
	{
		printf("Failed to load dot texture!\n");
		success = false;
	}

	return success;
}

//void Dot::handleEvent(SDL_Event& e)
//{
//	//If a key was pressed
//	if (e.type == SDL_KEYDOWN && e.key.repeat == 0)
//	{
//		//Adjust the velocity
//		switch (e.key.keysym.sym)
//		{
//		case SDLK_UP: mVelY -= c.getDotVel(); break;
//		case SDLK_DOWN: mVelY += c.getDotVel(); break;
//		case SDLK_LEFT: mVelX -= c.getDotVel(); break;
//		case SDLK_RIGHT: mVelX += c.getDotVel(); break;
//		}
//	}
//	//If a key was released
//	else if (e.type == SDL_KEYUP && e.key.repeat == 0)
//	{
//		//Adjust the velocity
//		switch (e.key.keysym.sym)
//		{
//		case SDLK_UP: mVelY += c.getDotVel(); break;
//		case SDLK_DOWN: mVelY -= c.getDotVel(); break;
//		case SDLK_LEFT: mVelX += c.getDotVel(); break;
//		case SDLK_RIGHT: mVelX -= c.getDotVel(); break;
//		}
//	}
//}

void Dot::move(float timeStep)
{

	//Move the dot left or right
	mPosX += mVelX * timeStep;

	//If the dot went too far to the left or right
	if (mPosX <= 0)
	{
		mVelX = -mVelX;
		resetPosition();
		player2 += 1;

	}
	else if (mPosX + c.getDotWidth() >= c.getScreenWidth())
	{
		mVelX = -mVelX;
		resetPosition();
		player1 += 1;

	}

	//Move the dot up or down
	mPosY += mVelY * timeStep;

	//If the dot went too far up or down
	if (mPosY < 0)
	{
		mVelY = -mVelY;
	}
	else if (mPosY + c.getDotHeight() > c.getScreenHeight())
	{
		mVelY = -mVelY;
	}

}

void Dot::render(SDL_Renderer* gRenderer)
{
	//Load dot texture
	if (!gDotTexture.loadFromFile("dot.bmp", gRenderer))
	{
		printf("Failed to load dot texture!\n");
	}

	//Show the dot
	gDotTexture.render((int)mPosX, (int)mPosY, gRenderer);
}

void Dot::resetPosition() {
	//Initialize the position
	mPosX = (float)c.getScreenWidth() / 2 - (float)c.getDotWidth();
	mPosY = (float)c.getScreenHeight() / 2 - (float)c.getDotHeight();
}

bool Dot::checkCollision(int ax, int ay)
{
	//The sides of the rectangles
	int ah;
	int aw;

	//Calculate dimensions of rect A
	aw = ax + c.getRacketWidth();
	ah = ay + c.getRacketHeight();

	if (mPosX + c.getDotWidth() >= ax && mPosX <= aw && mPosY >= ay && mPosY <= ah)
	{
		mVelX = -mVelX;
		float d = (float)c.getRacketHeight() / 4;
		float dotMiddle = mPosY + (c.getDotHeight() / 2);

		if (dotMiddle >= ay + d || dotMiddle <= ah - d)
		{
			mVelY = 0;
			d = d / 2;

			if (dotMiddle >= ay + d)
			{
				mVelY += 100;
				d = d / 2;
				printf("Haut de la barre M\n");

				if (dotMiddle >= ay + d)
				{
					mVelY += 100;
					printf("Haut de la barre B\n");
				}
			}
			else if (dotMiddle <= ah - d)
			{
				mVelY -= 100;
				d = d / 2;
				printf("Bas de la barre M\n");

				if (dotMiddle <= ah - d)
				{
					mVelY -= 100;
					printf("Bas de la barre B\n");
				}

			}
		}
		return true;
	}

	//If no collision
	return false;
}

void Dot::free()
{
	gDotTexture.free();
}
