/**
 *
 *	This file is part of GusGame
 *	Copyright (C) 2013-2015 Andreas Rönnquist
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
ALLEGRO_DISPLAY *GraphicsHandler::display = NULL;

Vector2d GraphicsHandler::screenSize;
Vector2d GraphicsHandler::backgroundSize;
	
float GraphicsHandler::zoomX = 1.0f, GraphicsHandler::zoomY = 1.0f;

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
void GraphicsHandler::setGraphicsMode(const Vector2d &size, bool fullscreen, bool resizable)
{
	int flags = 0;

	if (fullscreen) {
		flags |= ALLEGRO_FULLSCREEN;
	} else {
		flags |= ALLEGRO_WINDOWED;
	}

	flags |= ALLEGRO_OPENGL;

	if (resizable) flags |= ALLEGRO_RESIZABLE;

	al_set_new_display_flags(flags);

	display = al_create_display(size.x, size.y);

	screenSize = size;
	setBackgroundSize(screenSize);

	if (!display) {
		throw ExceptionLib::Exception("Couldn't init display!");
	}

	//al_set_window_position(display, 32, 32);
}


/**
 *
 */
void GraphicsHandler::setBackgroundSize(const Vector2d &size)
{
	backgroundSize = size;
	
	zoomX = (float)screenSize.x / (float)backgroundSize.x;
	zoomY = (float)screenSize.y / (float)backgroundSize.y;
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
	al_clear_to_color(al_map_rgb(0, 0, 0));
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
Rect GraphicsHandler::getScreenRect()
{
		return Rect(Vector2d(0, 0), screenSize);
}


/**
 *
 */
void GraphicsHandler::setClipRect(const Rect &rect)
{
	al_set_clipping_rectangle(rect.position.x, rect.position.y, rect.size.x, rect.size.y);
}


/**
 *
 */
void GraphicsHandler::noClip()
{
	setClipRect(getScreenRect());
}


/**
 *
 */
void GraphicsHandler::setIcon(Bitmap *icon)
{
	if (display) {
		if (icon) {
			al_set_display_icon(display, icon->getAllegroBitmap());
		}
	}
}

// end of namespace
// ----------------
};

// end of namespace
// ----------------
};
