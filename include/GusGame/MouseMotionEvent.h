/**
 *
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
#ifndef __HEADER_MOUSE_MOTION_EVENT_
#define __HEADER_MOUSE_MOTION_EVENT_

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
class MouseMotionEvent
{
public:
   MouseMotionEvent();
   explicit MouseMotionEvent(ALLEGRO_EVENT ev);

   explicit MouseMotionEvent(const GraphicsLib::Vector2d &position);
   virtual ~MouseMotionEvent();

   GraphicsLib::Vector2d getPosition() const;

protected:

   GraphicsLib::Vector2d m_Position;
};

// end of namespace
// ----------------
};

// end of namespace
// ----------------
};


#endif /*__HEADER_MOUSE_MOTION_EVENT_*/
