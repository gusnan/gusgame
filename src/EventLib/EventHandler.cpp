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
 
#include "KeyEvent.h"
#include "MouseButtonEvent.h"
#include "MouseMotionEvent.h"
#include "UserEvent.h"
#include "ActiveEvent.h"

#include "EventHandler.h"

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
EventHandler::EventHandler()
{
}


/**
 *
 */
EventHandler::~EventHandler()
{
}


/**
 *
 */
void EventHandler::handleKeyboard(KeyEvent &keyEvent)
{
	
}


/**
 *
 */
void EventHandler::handleActiveEvent(ActiveEvent &activeEvent)
{
}


/**
 *
 */
int EventHandler::handleUserEvent(UserEvent &event)
{
	return 0;
}


/**
 *
 */
void EventHandler::handleMouseButton(MouseButtonEvent &mouseButtonEvent)
{
}


/**
 *
 */
void EventHandler::handleMouseMotion(MouseMotionEvent &mouseMotionEvent)
{
}


/**
 *
 */
void EventHandler::handleQuitEvent()
{
}


/**
 *
 */
void EventHandler::handleSystemQuitEvent()
{
}


// end of namespace
// ----------------
};

// end of namespace
// ----------------
};
