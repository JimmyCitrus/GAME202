//==============================================================================
#include "CApp.h"


void
CApp::MoveSprites()
{
    int i;
    int window_w = WINDOW_WIDTH;
    int window_h = WINDOW_HEIGHT;
    SDL_Rect *position, *velocity;

    /* Draw a gray background */
    SDL_SetRenderDrawColor(renderer, 0xA0, 0xA0, 0xA0, 0xFF);
    SDL_RenderClear(renderer);

    /* Move the sprite, bounce at the wall, and draw */
    for (i = 0; i < NUM_SPRITES; ++i)
    {
        position = &positions[i];
        velocity = &velocities[i];
		if (i != 0)
		{
			position->x += velocity->x;
			if ((position->x < 0) || (position->x >= (window_w - sprite_w)))
			{
				velocity->x = -velocity->x;
				position->x += velocity->x;
			}
			position->y += velocity->y;
			if ((position->y < 0) || (position->y >= (window_h - sprite_h)))
			{
				velocity->y = -velocity->y;
				position->y += velocity->y;
			}
		}

     
		/* Blit the sprite onto the screen */
		if (i == 0)
		{
			SDL_RenderCopy(renderer, sprite, NULL, position);
		}
		else if (i == 1)
		{
			SDL_RenderCopy(renderer, spriteAlien, NULL, position);
		}
		else if (i == 2)
		{
			SDL_RenderCopy(renderer, spriteCannonball, NULL, position);
		}
		else if (i == 3)
		{
			SDL_RenderCopy(renderer, spriteFireball, NULL, position);
		}
    }
	SDL_RenderPresent(renderer);


}


//==============================================================================
void CApp::OnLoop()
{
    MoveSprites();
	if (joy)
	{
		//Don't need commented code below, Just need Y axis motion
		//positions[1].x += SDL_JoystickGetAxis(joy, 0) / 6000;
		positions[1].y += SDL_JoystickGetAxis(joy, 1) / 6000;
		if (positions[1].x > WINDOW_WIDTH - sprite_w)
			positions[1].x = WINDOW_WIDTH - sprite_w;

		if (positions[1].x < 0)
			positions[1].x = 0;
		if (positions[1].y > WINDOW_HEIGHT - sprite_h)
			positions[1].y = WINDOW_HEIGHT - sprite_h;

		if (positions[1].y < 0)
			positions[1].y = 0;
	}


}

//==============================================================================
