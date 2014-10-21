/**
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
}


/**
 *
 */
UserEvent::UserEvent(ALLEGRO_EVENT ev) : m_UserEventValue(), userEvent()
{
	m_UserEventValue=ev.user.data1;
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
	m_UserEventValue=source.m_UserEventValue;
	userEvent=source.userEvent;
}


/**
 *
 */
UserEvent &UserEvent::operator=(const UserEvent &source)
{
	if (this != &source) {

		m_UserEventValue=source.m_UserEventValue;
		userEvent=source.userEvent;
	}

	return *this;
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
	userEvent.user.type = SIMPLE_USER_EVENT_TYPE;
	userEvent.user.data1 = m_UserEventValue;

	if (!al_emit_user_event(&EventSystem::userEventSource, &userEvent, NULL)) {
		std::cout << "al_emit_user_event FAILED!" << std::endl;
	}
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
