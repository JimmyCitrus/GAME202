//==============================================================================
#include "CApp.h"

//==============================================================================


void CApp::OnRender()
{
		/* Update the screen! */
		SDL_RenderPresent(renderer);
		SDL_Delay(3);
	
}

//==============================================================================