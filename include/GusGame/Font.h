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
#ifndef __HEADER_GUSGAME_FONT_
#define __HEADER_GUSGAME_FONT_

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
class Font
{
public:
   Font();
   Font(const Font &source);

   Font &operator=(const Font &source);

   Font(std::string filename, int size, bool useKerning = false);
   virtual ~Font();

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

#endif /*__HEADER_GUSGAME_FONT_*/
