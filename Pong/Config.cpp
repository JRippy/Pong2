#include "pch.h"
#include "Config.h"

Config::Config()
{
}
int Config::getScreenHeight()
{
	return SCREEN_HEIGHT;
}

int Config::getScreenWidth()
{
	return SCREEN_WIDTH;
}

int Config::getDotHeight()
{
	return DOT_HEIGHT;
}

int Config::getDotWidth()
{
	return DOT_WIDTH;
}

int Config::getDotVel()
{
	return DOT_VEL;
}

int Config::getRacketHeight()
{
	return RACKET_HEIGHT;
}

int Config::getRacketWidth()
{
	return RACKET_WIDTH;
}

int Config::getRacketVel()
{
	return RACKET_VEL;
}

int Config::getMiniRacketHeight()
{
	return RACKET_MINI_HEIGHT;
}

int Config::getEndPartyGameScore()
{
	return END_PARTY_GAME;
}

