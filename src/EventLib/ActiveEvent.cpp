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
#include "Library.h"

#include "ActiveEvent.h"

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
ActiveEvent::ActiveEvent() : m_WindowState(WindowStateDefault)
{
}


/**
 *
 */
ActiveEvent::ActiveEvent(ALLEGRO_EVENT alEvent) : m_WindowState(WindowStateDefault)
{
	if (alEvent.type == ALLEGRO_EVENT_DISPLAY_SWITCH_IN) {
		m_WindowState = WindowStateAppFocusGain;
	} else if (alEvent.type == ALLEGRO_EVENT_DISPLAY_SWITCH_OUT) {
		m_WindowState = WindowStateAppFocusLost;
	} else if (alEvent.type == ALLEGRO_EVENT_MOUSE_LEAVE_DISPLAY) {
		m_WindowState = WindowStateMouseFocusLost;
	} else if (alEvent.type == ALLEGRO_EVENT_MOUSE_ENTER_DISPLAY) {
		m_WindowState = WindowStateMouseFocusGain;
	}
}


/**
 *
 */
ActiveEvent::ActiveEvent(ActiveWindowState windowState) : m_WindowState(windowState)
{
}


/**
 *
 */
ActiveEvent::~ActiveEvent()
{
}


/**
 *
 */
ActiveWindowState ActiveEvent::getWindowState()
{
	return m_WindowState;
}

// end of namespace
// ----------------
};

// end of namespace
// ----------------
};
