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
