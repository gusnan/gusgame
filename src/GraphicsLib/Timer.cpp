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
#include "Library.h"

#include "Timer.h"

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
double Timer::timerValue1 = 0.0f, Timer::timerValue2 = 0.0f;

double Timer::deltaTime = 0.0f;


/**
 *
 */
void Timer::initTimer()
{
   timerValue1 = timerValue2 = al_get_time();
}


/**
 *
 */
void Timer::doneTimer()
{
}


/**
 *
 */
void Timer::updateFrame()
{
   deltaTime = Timer::timerValue2 - timerValue1;
}


/**
 *
 */
double Timer::getDeltaTime()
{
   return deltaTime;
}

// end of namespace
// ----------------
};

// end of namespace
// ----------------
};
