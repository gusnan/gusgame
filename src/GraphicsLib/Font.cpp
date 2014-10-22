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

#include "Library.h"

#include "Vector2d.h"

#include "Color.h"

#include "Font.h"

#include "LogLib.h"

#include "FileHelper.h"

#include "ExceptionLib.h"

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
Font::Font() : m_AllegroFont(NULL)
{
}


/**
 *
 */
Font::Font(const Font &source) : m_AllegroFont(NULL)
{

}


/**
 *
 */
Font::Font(std::string filename, int size, bool useKerning) : m_AllegroFont(NULL)
{
	std::string fixedFilename = FileHelper::getFilename(filename);

	int flags = 0;

	m_AllegroFont = al_load_font((char*)(fixedFilename.c_str()), size, flags);

	if (!m_AllegroFont) {
		std::stringstream st;

		st << "File not found: " << fixedFilename;

		throw ExceptionLib::FileNotFoundException(st.str());
	}
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
	al_draw_text(m_AllegroFont, color.getAllegroColor(), position.x, position.y,
						ALLEGRO_ALIGN_LEFT, (char*)text.c_str());
}


/**
 *
 */
void Font::drawCenter(const Vector2d &position, std::string text, const Color &color, bool centerVertical)
{
	int subVertical = 0;
	if (centerVertical)
		subVertical = getHeight() / 2;

	al_draw_text(m_AllegroFont, color.getAllegroColor(), position.x, position.y - subVertical,
						ALLEGRO_ALIGN_CENTER, (char*)text.c_str());
}


/**
 *
 */
int Font::getHeight()
{
	int result = -1;

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
