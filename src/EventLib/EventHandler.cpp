/**
 *
 *	This file is part of GusGame
 *	Copyright (C) 2013-2014 Andreas Rönnquist
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

using namespace Gus;
using namespace GraphicsLib;

#include "KeyEvent.h"
#include "MouseButtonEvent.h"
#include "MouseMotionEvent.h"
#include "MouseScrollerEvent.h"
#include "UserEvent.h"
#include "ActiveEvent.h"
#include "ResizeEvent.h"

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
EventHandler::EventHandler(std::string name) : m_Name(name)
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
EventHandler::EventHandler(const EventHandler &source) : m_Name(source.m_Name)
{
   if (this != &source)
   {
      m_Name = source.m_Name;
   }

}


/**
 *
 */
EventHandler &EventHandler::operator=(const EventHandler &source)
{
   if (this != &source)
   {
      m_Name = source.m_Name;
   }

   return *this;
}



/**
 *
 */
bool EventHandler::handleKeyboard(KeyEvent &keyEvent)
{
   return false;
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
bool EventHandler::handleUserEvent(UserEvent &event)
{
   return false;
}


/**
 *
 */
bool EventHandler::handleMouseButton(MouseButtonEvent &mouseButtonEvent)
{
   return true;
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
void EventHandler::handleMouseScroller(MouseScrollerEvent &mouseScrollerEvent)
{
}


/**
 *
 */
void EventHandler::handleResizeEvent(ResizeEvent &resizeEvent)
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


/**
 *
 */
std::string EventHandler::getName()
{
   return m_Name;
}


/**
 *
 */
void EventHandler::setName(std::string inName)
{
   m_Name = inName;
}


/**
 *
 */
std::shared_ptr<EventHandler> EventHandler::makeCopy() const
{
   return cloneImplementation();
}


/**
 *
 */
std::shared_ptr<EventHandler> EventHandler::cloneImplementation() const
{
   return std::shared_ptr<EventHandler >(new EventHandler(*this));
}

// end of namespace
// ----------------
};

// end of namespace
// ----------------
};