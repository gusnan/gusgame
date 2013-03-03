/**
 *	This file is part of freedungeon
 *	Copyright (C) 2013 Andreas Rönnquist
 *
 *	freedungeon is free software: you can redistribute it and/or 
 *	modify it under the terms of the GNU General Public License as published 
 *	by the Free Software Foundation, either version 3 of the License, or
 *	(at your option) any later version.
 *
 *	freedungeon is distributed in the hope that it will be useful,
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *	GNU General Public License for more details.
 *
 *	You should have received a copy of the GNU General Public License
 *	along with freedungeon.  
 *	If not, see <http://www.gnu.org/licenses/>.
 */
#include <string>
#include <sstream>

#include "Library.h"

#include "Vector2d.h"

using namespace Gus;
using namespace GraphicsLib;

#include "MouseMotionEvent.h"

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
MouseMotionEvent::MouseMotionEvent(ALLEGRO_EVENT ev) : m_Position()
{
	
	m_Position.x = ev.mouse.x;
	m_Position.y = ev.mouse.y;
}


/**
 *
 */
MouseMotionEvent::MouseMotionEvent(const GraphicsLib::Vector2d &position) :
	m_Position(position)
{
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
