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
#include <boost/shared_ptr.hpp>

#include <sstream>
#include <string>
#include <vector>
#include <list>

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
UserEvent::UserEvent() : m_UserEventNumber(0), userEvent(), m_EventData()
{
	static int value = 1;

	m_UserEventNumber = ++value;
}


/**
 *
 */
UserEvent::UserEvent(ALLEGRO_EVENT ev) : m_UserEventNumber(), userEvent()
{
	m_UserEventNumber = ev.user.data1;
	m_EventData = (EventData*)ev.user.data2;
	//userEvent=ev;
}


/**
 *
 */
UserEvent::UserEvent(int inNumber) : m_UserEventNumber(inNumber), userEvent()
{
}


/**
 *
 */
UserEvent::UserEvent(const UserEvent &source) : m_UserEventNumber(), userEvent()
{
	userEvent = source.userEvent;
	m_UserEventNumber = source.m_UserEventNumber;
	m_EventData = source.m_EventData;
}


/**
 *
 */
UserEvent &UserEvent::operator=(const UserEvent &source)
{
	if (this != &source) {

		userEvent = source.userEvent;
		m_UserEventNumber = source.m_UserEventNumber;
		m_EventData = source.m_EventData;
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
void UserEvent::setEventData(EventData *eventData)
{
	m_EventData = eventData;
}


/**
 *
 */
EventData *UserEvent::getEventData()
{
	return m_EventData;
}

// end of namespace
// ----------------
};
