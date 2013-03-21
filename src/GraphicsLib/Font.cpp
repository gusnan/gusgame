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

#include "Vector2d.h"

#include "Color.h"

#include "Font.h"

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
Font::Font()
{
}


/**
 *
 */
Font::Font(std::string filename, int size, bool useKerning)
{
	
}


/**
 *
 */
Font::~Font()
{
}


/**
 *
 */
void Font::draw(const Vector2d &position, std::string text, const Color &color)
{
}

/**
 *
 */
void Font::drawCenter(const Vector2d &position, std::string text, const Color &color)
{
}


/**
 *
 */
int Font::getHeight()
{
	return 10;
}

// end of namespace
// ----------------
};

// end of namespace
// ----------------
};
