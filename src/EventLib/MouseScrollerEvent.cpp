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

#include "MouseScrollerEvent.h"


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
MouseScrollerEvent::MouseScrollerEvent() : m_Scroller(0)
{
}


/**
 *
 */
MouseScrollerEvent::MouseScrollerEvent(ALLEGRO_EVENT ev) : m_Scroller()
{
   m_Scroller = ev.mouse.z;
}

/**
 *
 */
MouseScrollerEvent::MouseScrollerEvent(const MouseScrollerEvent &source) : m_Scroller()
{
   m_Scroller = source.m_Scroller;
}


/**
 *
 */
MouseScrollerEvent::~MouseScrollerEvent()
{
}


/**
 *
 */
int MouseScrollerEvent::getScroller() const
{
   return m_Scroller;
}


/**
 *
 */
void MouseScrollerEvent::setScroller(int inValue)
{
   al_set_mouse_z(inValue);
}

/**
 *
 */
};

//
};
