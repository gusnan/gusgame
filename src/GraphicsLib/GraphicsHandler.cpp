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
#include <stdint.h>
#include <sstream>

#include "Library.h"

#include "Vector2d.h"
#include "Rect.h"

#include "Exception.h"

#include "Color.h"

#include "Bitmap.h"

#include "GraphicsHandler.h"

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
ALLEGRO_DISPLAY *GraphicsHandler::display=NULL;

ALLEGRO_MOUSE_CURSOR *GraphicsHandler::systemMouseCursor=NULL;

/**
 *
 */
void GraphicsHandler::initGraphicsHandler()
{
}


/**
 *
 */
void GraphicsHandler::doneGraphicsHandler()
{
	if (display) {
		al_destroy_display(display);
	}
	
	if (systemMouseCursor) {
		al_destroy_mouse_cursor(systemMouseCursor);
	}
}


/**
 *
 */
std::string GraphicsHandler::getOpenGLVersionString()
{
	uint32_t openGLversion = al_get_opengl_version();
	
	/*
	std::cout << ((openGLversion >> 24) % 0x100) << std::endl;
	std::cout << ((openGLversion >> 16) % 0x100) << std::endl;
	std::cout << ((openGLversion >> 8) % 0x100) << std::endl;
	std::cout << (openGLversion % 0x100) << std::endl;
	*/
	
	std::stringstream result;
	
	//result << openGLversion;

	result << ((openGLversion >> 24) % 0x100) << "." << 
				 ((openGLversion >> 16) % 0x100) << "." << 
				 ((openGLversion >> 8) % 0x100) << "."<< (openGLversion % 0x100);

	return (std::string)(result.str());
}


/**
 *
 */
void GraphicsHandler::setGraphicsMode(const Vector2d &size, bool fullscreen)
{
	int flags=0;
	
	if (fullscreen) {
		flags |= ALLEGRO_FULLSCREEN;
	} else {
		flags |= ALLEGRO_WINDOWED;
	}
	
	flags |= ALLEGRO_OPENGL;
	
	al_set_new_display_flags(flags);
	
	display=al_create_display(size.x,size.y);
	
	if (!display) {
		throw ExceptionLib::Exception("Couldn't init display!");
	}
	
	al_set_window_position(display, 32, 32);
}


/**
 *
 */
void GraphicsHandler::setWindowTitle(std::string windowTitle)
{
	if (display)
		al_set_window_title(display, (const char*)(windowTitle.c_str()));	
}


/**
 *
 */
void GraphicsHandler::clearScreen()
{
	al_clear_to_color(al_map_rgb(0,0,0));
}


/**
 *
 */
void GraphicsHandler::updateScreen()
{
	al_flip_display();
}


/**
 *
 */
void GraphicsHandler::setMouseBitmap(Bitmap *mouseBitmap)
{
	if (mouseBitmap) {
		systemMouseCursor = al_create_mouse_cursor(mouseBitmap->getAllegroBitmap(), 0,0);
	}
	
	if (systemMouseCursor) {
		if (display) {
			al_set_mouse_cursor(display, systemMouseCursor);
		}
	}
	
	
}

// end of namespace
// ----------------
};

// end of namespace
// ----------------
};
