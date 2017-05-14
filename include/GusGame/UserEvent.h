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
#ifndef __HEADER_USER_EVENT_
#define __HEADER_USER_EVENT_

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

#define SIMPLE_USER_EVENT_TYPE	ALLEGRO_GET_EVENT_TYPE('t', 'e', 's', 't')

/**
 *
 */
class UserEvent
{
public:
	UserEvent();
	UserEvent(ALLEGRO_EVENT ev);
	UserEvent(int value);

	UserEvent(const UserEvent &source);
	UserEvent &operator=(const UserEvent &source);

	bool operator==(const UserEvent &source) const;
	bool operator!=(const UserEvent &source) const;

	virtual ~UserEvent();

	void pushEvent();

	int getUserEventValue();

protected:
	int m_UserEventValue;

	ALLEGRO_EVENT userEvent;
};

// end of namespace
// ----------------
};

// end of namespace
// ----------------
};

#endif /*__HEADER_USER_EVENT_*/
