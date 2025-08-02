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
#ifndef __HEADER_GUSGAME_BITMAPFONT_
#define __HEADER_GUSGAME_BITMAPFONT_

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
class BitmapFont
{
public:
   BitmapFont();
   BitmapFont(const BitmapFont &source);

   BitmapFont &operator=(const BitmapFont &source);

   // BitmapFont(std::string filename, int size, bool useKerning = false);
   BitmapFont(std::string filename);
   virtual ~BitmapFont();

   void draw(const Vector2d &position, std::string text, const Color &color);

   void drawCenter(const Vector2d &position, std::string text, const Color &color, bool centerVertical = true);

   int getHeight();

protected:

   ALLEGRO_FONT *m_AllegroFont;

};

// end of namespace
// ----------------
};

// end of namespace
// ----------------
};

#endif /*__HEADER_GUSGAME_BITMAPFONT_*/
