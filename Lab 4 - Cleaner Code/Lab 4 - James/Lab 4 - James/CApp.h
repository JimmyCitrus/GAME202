//==============================================================================
// SDL Tutorial 1
//==============================================================================
#ifndef _CAPP_H_
#define _CAPP_H_

#include "SDL.h"

#define WINDOW_WIDTH    800
#define WINDOW_HEIGHT   600
#define NUM_SPRITES     4
#define MAX_SPEED       1

//==============================================================================
class CApp
{
private:
    bool            Running;

    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Texture *sprite;
	SDL_Texture *spriteCannonball;
	SDL_Texture *spriteAlien;
	SDL_Texture *spriteFireball;
    SDL_Rect positions[NUM_SPRITES];
    SDL_Rect velocities[NUM_SPRITES];
    int sprite_w, sprite_h;
	int mouse_x, mouse_y;
	SDL_Joystick *joy = NULL;

public:
    CApp();

    int OnExecute();

public:
    bool OnInit();

    void OnEvent(SDL_Event* Event);

    void OnLoop();

    void OnRender();
    int LoadSprite(char *file, SDL_Renderer *renderer, SDL_Texture *&someSprite);
    void MoveSprites();

    void OnCleanup();
};

//==============================================================================

#endif
