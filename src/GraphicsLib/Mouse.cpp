/**
 *
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
#include <string>
#include <sstream>
#include <vector>

#include "Library.h"

#include "Vector2d.h"
#include "Rect.h"

#include "Color.h"
#include "Bitmap.h"

#include "Mouse.h"

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


ALLEGRO_MOUSE_CURSOR *Mouse::systemMouseCursor=NULL;

Vector2d Mouse::mousePosition = Vector2d(0,0);

/**
 *
 */
void Mouse::initMouse()
{
}

/**
 *
 */
void Mouse::doneMouse()
{

	if (systemMouseCursor) {
		al_destroy_mouse_cursor(systemMouseCursor);
	}

}



/**
 *
 */
void Mouse::setMouseBitmap(Bitmap *mouseBitmap)
{
	if (mouseBitmap) {
		systemMouseCursor = al_create_mouse_cursor(mouseBitmap->getAllegroBitmap(), 0,0);
	}

	if (systemMouseCursor) {
		if (GraphicsHandler::display) {
			al_set_mouse_cursor(GraphicsHandler::display, systemMouseCursor);
		}
	}
}


// end of namespace
// ----------------
};

// end of namespace
// ----------------
};
