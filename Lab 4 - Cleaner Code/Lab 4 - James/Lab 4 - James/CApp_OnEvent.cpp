//==============================================================================
#include "CApp.h"


int i;

//==============================================================================
void CApp::OnEvent(SDL_Event* Event) {
    if(Event->type == SDL_QUIT||Event->type == SDL_KEYDOWN) {
        Running = false;
    }
	
	
			switch (Event->type)
			{
			case SDL_QUIT:
			
			case SDL_MOUSEMOTION:
			{
				SDL_GetMouseState(&mouse_x, &mouse_y);
			}
			case SDL_MOUSEBUTTONDOWN:
			{
				//If mouse button 1 is pressed, set coordinates of respective shot to the x of the alien
				//Set Velocity to actually travel across screen
				if (Event->button.button == 1)
				{
					positions[2].x = positions[0].x;
					positions[2].y = positions[0].y;
					velocities[2].x = -2;
				}
			}
			case SDL_JOYBUTTONDOWN:
				//If button 0 is pressed, set coordinates of respective shot to the x of the alien
				//Set Velocity to actually travel across screen
				if (Event->jbutton.which == 0)
				{
					positions[3].x = positions[1].x;
					positions[3].y = positions[1].y;
					velocities[3].x = 2;
				}
				break;
			

		}
	

		//Set Cannon to follow Y coordinates of the mouse 
		positions[0].y = mouse_y;

		//If the shot hits a wall, reset to offscreen position
		if (positions[2].x == 0)
		{
			positions[2].x = -100;
			velocities[2].x = 0;
		}
		if (positions[3].x == 690)
		{
			positions[3].x = -200;
			velocities[3].x = 0;
		}
	
}

//==============================================================================
