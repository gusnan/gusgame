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
#include "EventData.h"

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
EventData::EventData()
{
}


/**
 *
 */
EventData::~EventData()
{
}


// end of namespace Gus
};
