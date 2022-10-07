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

#include "Library.h"

#include "Vector2d.h"

#include "Color.h"

#include "Font.h"

#include "LogLib.h"

#include "FileHelper.h"

#include "ExceptionLib.h"

#include "Vector2d.h"
#include "Rect.h"
#include "GraphicsHandler.h"

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
Font::Font() : m_AllegroFont(nullptr)
{
}


/**
 *
 */
Font::Font(const Font &source) : m_AllegroFont(nullptr)
{

}


/**
 *
 */
Font::Font(std::string filename, int size, bool useKerning) : m_AllegroFont(nullptr)
{
   std::string fixedFilename = FileHelper::getFilename(filename);

   int flags = 0;

   m_AllegroFont = al_load_font(const_cast<char*>(fixedFilename.c_str()), size, flags);

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
      m_AllegroFont = NULL;
   }
}


/**
 *
 */
void Font::draw(const Vector2d &position, std::string text, const Color &color)
{
   float px = (float)position.x * (float)GraphicsHandler::instance().getZoomX();
   float py = (float)position.y * (float)GraphicsHandler::instance().getZoomY();

   al_draw_text(m_AllegroFont, color.getAllegroColor(), px, py,
                  ALLEGRO_ALIGN_LEFT, const_cast<char*>(text.c_str()));
}


/**
 *
 */
void Font::drawCenter(const Vector2d &position, std::string text, const Color &color, bool centerVertical)
{
   int subVertical = 0;
   if (centerVertical)
      subVertical = getHeight() / 2;
   
   float px = (float)position.x * (float)GraphicsHandler::instance().getZoomX();
   float py = (float)position.y * (float)GraphicsHandler::instance().getZoomY();

   al_draw_text(m_AllegroFont, color.getAllegroColor(), px, py - subVertical,
                  ALLEGRO_ALIGN_CENTER, const_cast<char*>(text.c_str()));
}


/**
 *
 */
int Font::getHeight()
{
   int result = -1;

   if (m_AllegroFont != nullptr) {
      result = al_get_font_line_height(m_AllegroFont);
   }


   return result;
}

// end of namespace
// ----------------
};

// end of namespace
// ----------------
};
