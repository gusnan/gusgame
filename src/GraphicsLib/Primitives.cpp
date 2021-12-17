/**
 *
 *	This file is part of GusGame
 *	Copyright (C) 2013-2017 Andreas Rönnquist
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
#include <memory>

#include "Library.h"

#include "Vector2d.h"
#include "Rect.h"
#include "Color.h"

#include "Primitives.h"

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
	float sx = (float)((float)sourcePoint.x + 0.5f);
	float sy = (float)((float)sourcePoint.y + 0.5f);
	
	float tx = (float)((float)targetPoint.x + 0.5f);
	float ty = (float)((float)targetPoint.y + 0.5f);
	
	float zx = GraphicsHandler::zoomX;
	float zy = GraphicsHandler::zoomY;
	
	al_draw_line(sx * zx, sy * zy, tx * zx, ty * zy, color.getAllegroColor(), thickness);
	
	/*
	al_draw_line((float)((float)sourcePoint.x + 0.5f), (float)((float)sourcePoint.y + 0.5f),
					 (float)((float)targetPoint.x + 0.5f), (float)((float)targetPoint.y + 0.5f), color.getAllegroColor(), thickness);
	*/
}


/**
 *
 */
void Primitives::rect(const Rect &rect, const Color &color, float thickness)
{
	float x = (float)rect.position.x;
	float y = (float)rect.position.y;
	
	float sx = (float)rect.size.x;
	float sy = (float)rect.size.y;
	
	float zx = GraphicsHandler::zoomX;
	float zy = GraphicsHandler::zoomY;

	al_draw_rectangle(x * zx,
							y * zy,
							x * zx + sx * zx,
							y * zy + sy * zy,
							color.getAllegroColor(),
							thickness);
}


/**
 *
 */
void Primitives::rectFill(const Rect &rect, const Color &color)
{
	
	float x = (float)rect.position.x;
	float y = (float)rect.position.y;
	
	float sx = (float)rect.size.x;
	float sy = (float)rect.size.y;
	
	float zx = (float)GraphicsHandler::zoomX;
	float zy = (float)GraphicsHandler::zoomY;

	al_draw_filled_rectangle(x * zx,
							y * zy,
							x * zx + sx * zx,
							y * zy + sy * zy,
							color.getAllegroColor());
	/*
	al_draw_filled_rectangle(rect.position.x,
									 rect.position.y,
									 rect.position.x + rect.size.x,
									 rect.position.y + rect.size.y,
									 color.getAllegroColor());
	*/
}


// end of namespace
// ----------------
};

// end of namespace
// ----------------
};
