/**
 *
 *	This file is part of GusGame
 *	Copyright (C) 2014 Andreas Rönnquist
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
 *
 */
#ifndef __HEADER_MOUSE_SCROLLER_EVENT_
#define __HEADER_MOUSE_SCROLLER_EVENT_

/**
 *
 */
namespace Gus
{

namespace EventLib
{

/**
 *
 */
class MouseScrollerEvent
{
public:
   MouseScrollerEvent();
   MouseScrollerEvent(ALLEGRO_EVENT ev);

   MouseScrollerEvent(const MouseScrollerEvent &source);

   virtual ~MouseScrollerEvent();

   int getScroller() const;
   void setScroller(int inValue);

protected:
   int m_Scroller;
};

//
};

//
};

#endif /*__HEADER_MOUSE_SCROLLER_EVENT_*/
