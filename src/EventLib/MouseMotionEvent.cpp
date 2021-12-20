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
#include <memory>

#include "Library.h"

#include "Vector2d.h"
#include "Rect.h"

#include "Color.h"

#include "Bitmap.h"

using namespace Gus;
using namespace GraphicsLib;

#include "MouseMotionEvent.h"

#include "Mouse.h"

/**
 *
 */
namespace Gus
{


/**
 *
 */
namespace EventLib
{


/**
 *
 */
MouseMotionEvent::MouseMotionEvent() : m_Position(Mouse::mousePosition)
{
}


/**
 *
 */
MouseMotionEvent::MouseMotionEvent(ALLEGRO_EVENT ev) : m_Position()
{

   m_Position.x = ev.mouse.x;
   m_Position.y = ev.mouse.y;

   Mouse::mousePosition = m_Position;
}


/**
 *
 */
MouseMotionEvent::MouseMotionEvent(const GraphicsLib::Vector2d &position) :
   m_Position(position)
{
   Mouse::mousePosition = m_Position;
}


/**
 *
 */
MouseMotionEvent::~MouseMotionEvent()
{
}


/**
 *
 */
Vector2d MouseMotionEvent::getPosition() const
{
   return m_Position;
}

/**
 *
 */

// end of namespace
// ----------------
};

// end of namespace
// ----------------
};
