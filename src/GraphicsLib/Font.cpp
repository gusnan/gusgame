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

#include "Library.h"

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
Font::Font() : m_AllegroFont()
{
}


/**
 *
 */
Font::Font(const Font &source) : m_AllegroFont()
{
	
}


/**
 *
 */
Font::Font(std::string filename, int size, bool useKerning) : m_AllegroFont()
{
	
}


/**
 *
 */
Font &Font::operator=(const Font &source)
{
	if (this != &source) {
	}
	
	return *this;
}



/**
 *
 */
Font::~Font()
{
	if (m_AllegroFont) {
		al_destroy_font(m_AllegroFont);
	}
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
	int result=-1;
	
	if (m_AllegroFont!=NULL) {
		result=al_get_font_line_height(m_AllegroFont);
	}
	
	
	return result;
}

// end of namespace
// ----------------
};

// end of namespace
// ----------------
};
