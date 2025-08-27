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
#include <string>
#include <vector>
#include <list>
#include <memory>

#include "Library.h"

#include "LogLib.h"

#include "GraphicsLib.h"
#include "Vector2d.h"

#include "KeyEvent.h"
#include "ActiveEvent.h"
#include "EventData.h"
#include "UserEvent.h"
#include "MouseButtonEvent.h"
#include "MouseMotionEvent.h"
#include "MouseScrollerEvent.h"
#include "ResizeEvent.h"

#include "EventHandler.h"
#include "EventSystem.h"

/**
 *
 */
namespace Gus
{


/**
 *
 */

using namespace EventLib;


/**
 *
 */
UserEvent::UserEvent() : m_UserEventNumber(0), userEvent() /*, /*m_EventString(""), m_CStyleString(NULL) */
{
   static int value = 1;

   m_UserEventNumber = ++value;
}


/**
 *
 */
UserEvent::UserEvent(ALLEGRO_EVENT ev) : m_UserEventNumber(), userEvent() /*m_EventString(""), m_CStyleString(NULL) */
{
   m_UserEventNumber = ev.user.data1;

   userEvent.user = ev.user;

   userEvent.user.data1 = ev.user.data1;
   userEvent.user.data2 = ev.user.data2;

}


/**
 *
 */
UserEvent::UserEvent(const UserEvent &source) : m_UserEventNumber(), userEvent() /*m_EventData(),*/ /*m_EventString(source.m_EventString), m_CStyleString(NULL) */ 
{
   userEvent = source.userEvent;
   userEvent.user.data1 = source.userEvent.user.data1;
   userEvent.user.data2 = source.userEvent.user.data2;

   m_UserEventNumber = source.m_UserEventNumber;
}



UserEvent::UserEvent(UserEvent *source) : m_UserEventNumber(), userEvent()
{
   userEvent = source->userEvent;
   userEvent.user.data1 = source->userEvent.user.data1;
   userEvent.user.data2 = source->userEvent.user.data2;

   m_UserEventNumber = source->m_UserEventNumber;

   m_UserEventNumber = source->m_UserEventNumber;
}


/**
 *
 */
UserEvent::UserEvent(const UserEvent *source) : m_UserEventNumber(), userEvent()
{
   userEvent = source->userEvent;
   userEvent.user.data1 = source->userEvent.user.data1;
   userEvent.user.data2 = source->userEvent.user.data2;

   m_UserEventNumber = source->m_UserEventNumber;

   m_UserEventNumber = source->m_UserEventNumber;
}

/**
 *
 */
UserEvent &UserEvent::operator=(const UserEvent &source)
{
   if (this != &source) {

      m_UserEventNumber = source.m_UserEventNumber;

      userEvent.user = source.userEvent.user;
      userEvent.user.data1 = source.userEvent.user.data1;
      userEvent.user.data2 = source.userEvent.user.data2;
   }

   return *this;
}

/**
 *
 */
bool UserEvent::operator==(const UserEvent &source) const
{
   if (m_UserEventNumber == source.m_UserEventNumber) {
      return true;
   }

   return false;
}


/**
 *
 */
bool UserEvent::operator!=(const UserEvent &other) const {
   return !(*this == other);
}


/**
 *
 */
UserEvent::~UserEvent()
{
   // delete the memory for the string
   // free(m_CStyleString);
}


/**
 *
 */
void UserEvent::pushEvent()
{
   EventSystem::listDelayedEvents->push_back(this);
}


/**
 *
 */
int UserEvent::getUserEventNumber()
{
   return m_UserEventNumber;
}


/**
 *
 */
void UserEvent::setUserEventNumber(int inNumber)
{
   m_UserEventNumber = inNumber;
}



/**
 *
 */
std::string UserEvent::getEventString()
{
   std::string result = "";

   char *temp = (char*)(userEvent.user.data2);

   std::stringstream st;

   if (temp != NULL) {
      st << "" << temp;
   }
   return st.str(); //result;
}


/**
 *
 */

void UserEvent::setEventString(const std::string &inString)
{
   char *temp = (char*)inString.c_str();
   sprintf(m_CStyleString, "%s", (char*)temp);

   userEvent.user.data2 = (intptr_t)(m_CStyleString);
}


/**
 *
 */
void UserEvent::print()
{
   std::stringstream st;

   std::string eventString = getEventString();
   st << "-- Userevent string :";
   st << eventString;

   STLOG(st);
}

// end of namespace
// ----------------
};
