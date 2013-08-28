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

#include <string>
#include <sstream>
#include <list>

#include "Exception.h"

using namespace Gus::ExceptionLib;

#include "Library.h"

#include "Vector2d.h"
#include "Rect.h"

#include "Color.h"
#include "Bitmap.h"

#include "Mouse.h"

#include "System.h"

#include "FileHelper.h"

/**
 *
 */
namespace Gus
{

/**
 *
 */
void System::initSystem()
{
	// Init Allegro
	if (!al_init()) {
		throw Exception("Couldn't init allegro!");
	}
	
	if (!al_init_image_addon()) {
		throw Exception("Couldn't init image addon!");
	}
	
	if (!al_install_keyboard()) {
		throw Exception("Couldn't install keyboard!");
	}
	
	if (!al_install_mouse()) {
		throw Exception("Couldn't init mouse!");
	}
	
	FileHelper::addDataFolder("data/");
	FileHelper::addDataFolder("../data/");
	FileHelper::addDataFolder("../../data/");
	
}


/**
 *
 */
void System::doneSystem()
{
	al_uninstall_mouse();
	
	al_uninstall_system();
}



/**
 *
 */
std::string System::getGusGameVersion()
{
	std::stringstream st;

	st << "0.01";
	
	return (std::string)st.str();
}



// end of namespace
// ----------------
};
