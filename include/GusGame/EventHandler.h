/**
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
#ifndef __HEADER_EVENT_HANDLER_
#define __HEADER_EVENT_HANDLER_

#include "DynamicLink.h"

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
class EventHandler
{
public:
	GUSGAME_DLL EventHandler(std::string inName="");
	GUSGAME_DLL virtual ~EventHandler();

	virtual GUSGAME_DLL void handleKeyboard(KeyEvent &keyEvent);
	virtual GUSGAME_DLL void handleActiveEvent(ActiveEvent &activeEvent);
	virtual GUSGAME_DLL int handleUserEvent(UserEvent &event);
	virtual GUSGAME_DLL void handleMouseButton(MouseButtonEvent &mouseButtonEvent);
	virtual GUSGAME_DLL void handleMouseMotion(MouseMotionEvent &mouseMotionEvent);
	virtual GUSGAME_DLL void handleQuitEvent();
	virtual GUSGAME_DLL void handleSystemQuitEvent();

	std::string getName();
	
protected:
	std::string m_Name;
};

// end of namespace
// ----------------
};

// end of namespace
// ----------------
};

#endif /*__HEADER_EVENT_HANDLER_*/
