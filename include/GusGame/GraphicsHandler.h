/**
 *	This file is part of GusGame
 *	Copyright (C) 2013 Andreas Rönnquist
 *
 *	GusGame is free software: you can redistribute it and/or 
 *	modify it under the terms of the GNU General Public License as published 
 *	by the Free Software Foundation, either version 3 of the License, or
 *	(at your option) any later version.
 *
 *	GusGame is distributed in the hope that it will be useful,
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *	GNU General Public License for more details.
 *
 *	You should have received a copy of the GNU General Public License
 *	along with GusGame.  
 *	If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef __HEADER_GRAPHICS_HANDLER_
#define __HEADER_GRAPHICS_HANDLER_

#include "Bitmap.h"

/**
 *
 */
namespace Gus
{

/**
 *
 */
namespace GraphicsLib
{

/**
 *
 */
namespace GraphicsHandler
{
	void initGraphicsHandler();
	void doneGraphicsHandler();
	
	void setGraphicsMode(const Vector2d &size, bool fullscreen);
	
	void setWindowTitle(std::string title);
	
	void clearScreen();
	void updateScreen();
	
	Rect getScreenRect();
	
	void setClipRect(const Rect &rect);
	void noClip();
	
	
	std::string getOpenGLVersionString();
	
	void setMouseBitmap(Gus::GraphicsLib::Bitmap *mouseBitmap);
	
	extern ALLEGRO_DISPLAY *display;
	
	extern ALLEGRO_MOUSE_CURSOR *systemMouseCursor;

	extern Vector2d screenSize;
};

// end of namespace
// ----------------
};

// end of namespace
// ----------------
};


#endif
