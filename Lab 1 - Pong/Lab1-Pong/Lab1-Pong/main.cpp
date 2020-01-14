/*
Name: James McElligott
Course: Game Programming
Prof: Majid Moghadam
Title of program: Object Oriented Programming
Date: 1/13/20
*/

//Include the SDL Library (required for all SDL projects)
#include"SDL.h"
#include <cstdio>
#include <cstdlib>

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
SDL_Rect CenterLine;

//
SDL_Event event;

//Mouse coordinates
int mouse_x, mouse_y;

//Speed and direction
int speed_x, speed_y;
int direction[2] = { -1, 1 };

bool check_collision(SDL_Rect A, SDL_Rect B)
{
	//The sides of the rectangle
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	//calculate the sides of rect A
	leftA = A.x;
	rightA = A.x + A.w;
	topA = A.y;
	bottomA = A.y + A.h;

	//calculate the sides of rect B
	leftB = B.x;
	rightB = B.x + B.w;
	topB = B.y;
	bottomB = B.y + B.h;

	//if any of the sides from A are outside of B
	if (bottomA <= topB)
	{
		return false;
	}
	if (topA >= bottomB)
	{
		return false;
	}
	if (rightA <= leftB)
	{
		return false;
	}
	if (leftA >= rightB)
	{
		return false;
	}

	//If none of the sides of A are outside B
	return true;
}

/*
The purpose of the LoadGame function:
*/

void LoadGame()
{
	//Create a pointer of the window
	SDL_Window *window;

	//Initialize speed
	speed_x = -1;
	speed_y = -1;

	//Creating a window with all it's attributes
	window = SDL_CreateWindow("Basic SDL Sprites",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		WINDOW_WIDTH, WINDOW_HEIGHT,
		SDL_WINDOW_SHOWN);
	if (!window)
	{
		return;
	}

	//If the renderer is not opening, close the program
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

	CenterLine.x = 395;
	CenterLine.y = 10;
	CenterLine.h = 580;
	CenterLine.w = 10;

}

/*
Purpose of the input function: To get user input
*/

void Input()
{
	//Queue events
	while (SDL_PollEvent(&event))
	{
		//Track mouse movement
		if (event.type == SDL_MOUSEMOTION)
		{
			SDL_GetMouseState(&mouse_x, &mouse_y);
		}
		//Clicking x or pressing F4
		if (event.type == SDL_QUIT)
		{
			running = false;
		}
		//Pressing a key
		if (event.type == SDL_KEYDOWN)
		{
			switch (event.key.keysym.sym)
			{
				//Pressing ESC exits the game
			case SDLK_ESCAPE:
				running = false;
				break;
			}
		}
		
	}
}

/*
Purpose of the update function: To constantly check for certain conditions
*/

void Update()
{
	PlayerPaddle.y = mouse_y;

	Ball.x += speed_x;
	Ball.y += speed_y;

	//reset ball to center screen
	if (Ball.x < 0 || Ball.x > WINDOW_WIDTH)
	{
		Ball.x = WINDOW_WIDTH / 2;
		Ball.y = WINDOW_HEIGHT / 2;
		//This expression produces random numbers -1, -2, 1 and 2
		speed_x = (rand() % 2 + 1) * direction[rand() % 2];
		speed_y = (rand() % 2 + 1) * direction[rand() % 2];
	}

	//Check the ball's y position
	if (Ball.y < 0 || Ball.y > WINDOW_HEIGHT - Ball.h)
	{
		speed_y = -speed_y;
	}

	if (PlayerPaddle.y < 0  || PlayerPaddle.y > WINDOW_HEIGHT - PlayerPaddle.h)
	{
		PlayerPaddle.y = 500;
	}

	SDL_Delay(10);

	AIPaddle.y = Ball.y - AIPaddle.h / 2 + Ball.h / 2;

	if (check_collision(Ball, AIPaddle) || check_collision(Ball, PlayerPaddle))
	{
		speed_x = -speed_x;
	}
}

/*
Purpose of the DrawScreen function: To draw everything on screen for the user to see
*/

void DrawScreen()
{
	//Clear the current render so that it can be redrawn
	SDL_RenderClear(renderer);

	//Setting the color of the background
	SDL_Rect background = { 0, 0, 800, 600 };
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderFillRect(renderer, &background);

	//Setting the colors of the Paddles and Center line
	SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
	SDL_RenderFillRect(renderer, &PlayerPaddle);

	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_RenderFillRect(renderer, &AIPaddle);

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderFillRect(renderer, &CenterLine);

	//Setting the color of the ball
	SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
	SDL_RenderFillRect(renderer, &Ball);

	//Re-render the visuals so everything is updated
	SDL_RenderPresent(renderer);
}

/*
Purpose of the Quit function: To exit the program when need be
*/

void Quit()
{
	//The SDL command to exit the program
	SDL_Quit();
}

/*
Purpose of the Main function: To initialize the game loop for the user to play
*/

int main(int argc, char *argv[])
{
	//Load the game before anything starts
	LoadGame();

	//While the game is running, call these functions
	while (running == true)
	{
		Input();              //Call the input function to check for user input
		Update();             //Call update to check for conditions changing
		DrawScreen();         //Call Draw so that there is a screen to display with the game
	}

	//Else, quit the program
	Quit();

	return 0;
}

