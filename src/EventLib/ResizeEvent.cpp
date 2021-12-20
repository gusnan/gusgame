/**
 *
 *	This file is part of GusGame
 *	Copyright (C) 2018 Andreas Rönnquist
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
#include <iostream>
#include <memory>

#include "Library.h"

#include "Vector2d.h"
#include "Rect.h"

using namespace Gus;
using namespace GraphicsLib;

#include "GraphicsLib.h"


#include "ResizeEvent.h"

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
ResizeEvent::ResizeEvent() : m_Rect(0, 0, 0, 0)
{
}


/**
 *
 */
ResizeEvent::ResizeEvent(ALLEGRO_EVENT alEvent) : m_Rect(0, 0, 0, 0)
{
   if (alEvent.type == ALLEGRO_EVENT_DISPLAY_RESIZE) {
      
      ALLEGRO_DISPLAY *display = alEvent.display.source;
      
      al_acknowledge_resize(display);
      
      m_Rect = Rect(alEvent.display.x, alEvent.display.y, alEvent.display.width, alEvent.display.height);
   }
}


/**
 *
 */
GraphicsLib::Rect ResizeEvent::getRect()
{
   return m_Rect;
}

/**
 *
 */
ResizeEvent::~ResizeEvent()
{
}

// end of namespace
// ----------------
};

// end of namespace
// ----------------
};
