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

#include <string>
#include <sstream>
#include <list>
#include <memory>

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

std::string System::executablePath = "";
std::string System::executableFilename = "";

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


	ALLEGRO_PATH *path_including_filename = al_get_standard_path(ALLEGRO_EXENAME_PATH);

	const char *char_filename = al_path_cstr(path_including_filename, '/');

	ALLEGRO_PATH *path = al_create_path(char_filename);

	al_set_path_filename(path, nullptr);

	const char *char_directory = al_path_cstr(path, '/');

	executableFilename = char_filename;

	executablePath = char_directory;

	al_destroy_path(path);
	al_destroy_path(path_including_filename);

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


/**
 *
 */
int System::getRamSize()
{
	return al_get_ram_size();
}


/**
 *
 */
std::string System::getAllegroVersionString()
{
	uint32_t version = al_get_allegro_version();
	int major = version >> 24;
	int minor = (version >> 16) & 255;
	int revision = (version >> 8) & 255;
	int release = version & 255;

	std::stringstream st;
	st << "" << major << "." << minor << "." << revision << "." << release;

	std::string result = st.str();

	return result;
}


/**
 *
 */
std::string System::getAppName()
{
	std::string result = "";

	result = (std::string)(al_get_app_name());

	return result;
}


// end of namespace
// ----------------
};
