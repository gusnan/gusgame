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
#include <sstream>

#include "Library.h"

#include "Vector2d.h"
#include "Color.h"

#include "Primitives.h"

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
void Primitives::initPrimitives()
{
	al_init_primitives_addon();
}


/**
 *
 */
void Primitives::donePrimitives()
{
	al_shutdown_primitives_addon();
}


/**
 *
 */
void Primitives::line(const Vector2d &sourcePoint, const Vector2d &targetPoint, const Color &color, float thickness)
{
	al_draw_line(sourcePoint.x, sourcePoint.y, targetPoint.x, targetPoint.y, color.getAllegroColor(), thickness);
}

// end of namespace
// ----------------
};

// end of namespace
// ----------------
};
