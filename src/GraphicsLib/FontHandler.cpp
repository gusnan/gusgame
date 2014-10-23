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

#include "Vector2d.h"

#include "Color.h"

#include "Library.h"

#include "Font.h"

#include "FontHandler.h"

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
void FontHandler::initFontHandler()
{
	al_init_font_addon();
	al_init_ttf_addon();
}


/**
 *
 */
void FontHandler::doneFontHandler()
{
	al_shutdown_ttf_addon();
	al_shutdown_font_addon();
}

// end of namespace
// ----------------
};

// end of namespace
// ----------------
};
