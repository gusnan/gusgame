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
#include <string>
#include <sstream>

#include "Library.h"

#include "GraphicsLib.h"

#include "MouseButtonEvent.h"

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
MouseButtonEvent::MouseButtonEvent(ALLEGRO_EVENT event) : 
	m_Position(event.mouse.x, event.mouse.y),
	m_Button(event.mouse.button),
	m_Status(MouseButtonStatusPressed)
{
	// We default to "pressed", check if it really is a "released" event
	if (event.type==ALLEGRO_EVENT_MOUSE_BUTTON_UP) {
		m_Status=MouseButtonStatusReleased;
	}
	
}


/**
 *
 */
MouseButtonEvent::~MouseButtonEvent()
{
}


/**
 *
 */
Gus::GraphicsLib::Vector2d MouseButtonEvent::getPosition() const
{
	return m_Position;
}


/**
 *
 */
int MouseButtonEvent::getButton() const
{
	return m_Button;
}


/**
 *
 */
MouseButtonStatus MouseButtonEvent::getStatus() const
{
	return m_Status;
}

// end of namespace
// ----------------
};

// end of namespace
// ----------------
};
