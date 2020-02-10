//==============================================================================
#include "CApp.h"
#include <stdlib.h>
#include <time.h>
//==============================================================================
bool CApp::OnInit()
{

    int i;

    /*if(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_JOYSTICK)<0)
    {
        return false;
    }*/
    window = SDL_CreateWindow("Basic SDL 2.0 Sprites",
                              100,
                              100,
                              WINDOW_WIDTH, WINDOW_HEIGHT,
                              SDL_WINDOW_SHOWN);
	if (!window)
	{
		OnCleanup();
	}
    renderer = SDL_CreateRenderer(window, -1, 0);
    if (!renderer)
        return false;
		

	if (LoadSprite("cannon.bmp", sprite) < 0)
	{
		return false;
	}
	if (LoadSprite("alien.bmp", spriteAlien) < 0)
	{
		return false;
	}
	if (LoadSprite("cannonball.bmp", spriteCannonball) < 0)
	{
		return false;
	}
	if (LoadSprite("fireball.bmp", spriteFireball) < 0)
	{
		return false;
	}

	SDL_InitSubSystem(SDL_INIT_JOYSTICK);

	if (SDL_NumJoysticks() > 0)
	{
		joy = SDL_JoystickOpen(0);

	}

    srand(time(NULL));
    for (i = 0; i < NUM_SPRITES; ++i) 
	{
		//positions[i].x = rand() % (WINDOW_WIDTH - sprite_w);
		  //positions[i].y = rand() % (WINDOW_HEIGHT - sprite_h);
		positions[i].w = sprite_w;
		positions[i].h = sprite_h;
		//Position alien and cannon in respective starting point
		positions[0].x = WINDOW_WIDTH - sprite_w;
		positions[0].y = 0;
		positions[1].x = 0;
		positions[1].y = 0;
		//Draw projectiles off screen for now
		positions[2].x = -100;
		positions[2].y = 0;
		positions[3].x = -200;
		positions[3].y = 0;
		//Initialize velocities
		velocities[i].x = 0;
		velocities[i].y = 0;
		velocities[0].x = 0;
		velocities[0].y = 0;
		velocities[1].x = 0;
		velocities[1].y = 0;


    }

    return true;
}

//==============================================================================
