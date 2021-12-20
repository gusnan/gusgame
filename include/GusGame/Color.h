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
#ifndef __HEADER_COLOR_
#define __HEADER_COLOR_

#include "Library.h"

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
class Color
{
public:
   Color();
   Color(float, float, float);
   Color(float, float, float, float);

   Color(ALLEGRO_COLOR allegroColor);

   Color(const Color &source);
   Color &operator=(const Color &source);

   virtual ~Color();

   ALLEGRO_COLOR getAllegroColor() const;

   float m_Red, m_Green, m_Blue, m_Alpha;

protected:
};

extern Color colorBlack;
extern Color colorWhite;
extern Color colorRed;
extern Color colorDarkRed;
extern Color colorGreen;
extern Color colorBlue;
extern Color colorYellow;
extern Color colorLightGray;
extern Color colorMediumGray;
extern Color colorDarkGray;

Color getColorFromString(const std::string& st);
Color getMiddleColor(Color col1,Color col2);
Color makeColorInt(int r,int g,int b);


// end of namespace
// ----------------
};

// end of namespace
// ----------------
};

#endif /*__HEADER_COLOR_*/
