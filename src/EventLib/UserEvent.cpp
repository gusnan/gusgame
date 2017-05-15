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
UserEvent::UserEvent() : m_UserEventValue(0), userEvent()
{
	static int value = 1;

	m_UserEventValue = ++value;
}


/**
 *
 */
UserEvent::UserEvent(ALLEGRO_EVENT ev) : m_UserEventValue(), userEvent()
{
	m_UserEventValue = ev.user.data1;
	//userEvent=ev;
}


/**
 *
 */
UserEvent::UserEvent(int value) : m_UserEventValue(value), userEvent()
{
}

/**
 *
 */
UserEvent::UserEvent(const UserEvent &source) : m_UserEventValue(), userEvent()
{
	userEvent = source.userEvent;
	m_UserEventValue = source.m_UserEventValue;
}


/**
 *
 */
UserEvent &UserEvent::operator=(const UserEvent &source)
{
	if (this != &source) {

		userEvent = source.userEvent;
		m_UserEventValue = source.m_UserEventValue;
	}

	return *this;
}


/**
 *
 */
bool UserEvent::operator==(const UserEvent &source) const
{
	if (m_UserEventValue == source.m_UserEventValue) {
		return true;
	}

	return false;
}


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
int UserEvent::getUserEventValue()
{
	return m_UserEventValue;
}


// end of namespace
// ----------------
};
