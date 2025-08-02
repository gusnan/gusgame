/**
 *
 *	This file is part of GusGame
 *	Copyright (C) 2025 Andreas Rönnquist
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

#include "BitmapFont.h"

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
BitmapFont::BitmapFont() : m_AllegroFont(nullptr)
{
}


/**
 *
 */
BitmapFont::BitmapFont(const BitmapFont &source) : m_AllegroFont(nullptr)
{

}

/**
 *
 */
BitmapFont::BitmapFont(std::string filename) : m_AllegroFont(nullptr)
{
   int range[2];
   
   std::string fixedFilename = FileHelper::getFilename(filename);
   
   ALLEGRO_BITMAP *font_bitmap;
   
   /* We assume a single unicode range, starting at the space
    * character.
    */
   range[0] = 32;
   range[1] = 32 + 128;
   
   ALLEGRO_BITMAP *temp_bitmap;
 
   font_bitmap = al_load_bitmap(const_cast<char*>(fixedFilename.c_str()));
     
   int w = al_get_bitmap_width(font_bitmap);
   int h = al_get_bitmap_height(font_bitmap);
   
   float zoomX = GraphicsHandler::instance().getZoomX();
   float zoomY = GraphicsHandler::instance().getZoomY();
   
   temp_bitmap = al_create_bitmap(w * zoomX, h * zoomY);
  
   al_set_target_bitmap(temp_bitmap);
   
   al_draw_scaled_bitmap(font_bitmap, 0, 0, w, h, 0, 0, w * zoomX, h * zoomY, 0);
   
   GraphicsHandler::instance().setTarget(nullptr);
   
   m_AllegroFont = al_grab_font_from_bitmap(temp_bitmap, 1, range);

   if (!m_AllegroFont) {
      std::stringstream st;

      st << "Couldn't convert from Bitmap to font: " << fixedFilename;

      throw ExceptionLib::FileNotFoundException(st.str());
   }
}


/**
 *
 */
BitmapFont &BitmapFont::operator=(const BitmapFont &source)
{
   if (this != &source) {
   }

   return *this;
}



/**
 *
 */
BitmapFont::~BitmapFont()
{
   if (m_AllegroFont) {
      al_destroy_font(m_AllegroFont);
      m_AllegroFont = NULL;
   }
}


/**
 *
 */
void BitmapFont::draw(const Vector2d &position, std::string text, const Color &color)
{
   float px = (float)position.x * (float)GraphicsHandler::instance().getZoomX();
   float py = (float)position.y * (float)GraphicsHandler::instance().getZoomY();

   al_draw_text(m_AllegroFont, color.getAllegroColor(), px, py,
                  ALLEGRO_ALIGN_LEFT, const_cast<char*>(text.c_str()));
}


/**
 *
 */
void BitmapFont::drawCenter(const Vector2d &position, std::string text, const Color &color, bool centerVertical)
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
int BitmapFont::getHeight()
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
