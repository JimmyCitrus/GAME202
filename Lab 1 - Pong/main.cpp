/*
Name: James McElligott
Course: Game Programming
Prof: Majid Moghadam
Title of program: Object Oriented Programming
Date: 1/13/20
*/

//Include the SDL Library (required for all SDL projects)
#include"SDL.h"

//Defining the window's width and height
#define WINDOW_WIDTH     800
#define WINDOW_HEIGHT    600

//Create the renderer
SDL_Renderer *renderer;

//Check if the game is running
bool running = true;

//Create the game objects
SDL_Rect PlayerPaddle;
SDL_Rect AIPaddle;
SDL_Rect Ball;

/*
The purpose of the LoadGame function:
*/

void LoadGame()
{
	//Create a pointer of the window
	SDL_Window *window;

	//
	window = SDL_CreateWindow("Basic SDL Sprites",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		WINDOW_WIDTH, WINDOW_HEIGHT,
		SDL_WINDOW_SHOWN);
	if (!window)
	{
		return;
	}

	//
	renderer = SDL_CreateRenderer(window, -1, 0);
	if (!renderer)
	{
		return;
	}

	//Defining the player paddle's attributes
	PlayerPaddle.x = 20;
	PlayerPaddle.y = 250;
	PlayerPaddle.h = 100;
	PlayerPaddle.w = 20;

	//Defining the AI paddle's attributes
	AIPaddle.x = 760;
	AIPaddle.y = 250;
	AIPaddle.h = 100;
	AIPaddle.w = 20;

	//Defining the ball's attributes
	Ball.x = 370;
	Ball.y = 290;
	Ball.h = 20;
	Ball.w = 20;

}