/**
 *
 *	This file is part of GusGame
 *	Copyright (C) 2017 Andreas Rönnquist
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
#ifndef __HEADER_TIMER_
#define __HEADER_TIMER_

/**
 *
 */
namespace Gus
{


/**
 *
 */
namespace GraphicsLib
{


/**
 *
 */
namespace Timer
{
   void initTimer();
   void doneTimer();

   void updateFrame();

   double getDeltaTime();

   extern double timerValue1, timerValue2;

   extern double deltaTime;

};

};

};


#endif /*__HEADER_TIMER_*/
