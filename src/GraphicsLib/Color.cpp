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

#include "Library.h"

#include "Color.h"

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
Color colorBlack = Color(0.0f, 0.0f, 0.0f, 1.0f);
Color colorWhite = Color(1.0f, 1.0f, 1.0f, 1.0f);
Color colorRed = Color(1.0f, 0.0f, 0.0f, 1.0f);
Color colorDarkRed = Color(0.6f, 0.0f, 0.0f, 1.0f);
Color colorGreen = Color(0.0f, 0.8f, 0.0f, 1.0f);
Color colorBlue = Color(0.0f, 0.0f, 1.0f, 1.0f);
Color colorYellow = Color(1.0f, 1.0f, 0.0f, 1.0f);
Color colorLightGray = Color(0.8f, 0.8, 0.8f, 1.0f);
Color colorDarkGray = Color(0.3125f, 0.3125f, 0.3125f, 1.0f);
Color colorMediumGray = Color(0.4375f, 0.4375f, 0.4375f, 1.0f);
Color colorCyan = Color(0.0f, 0.859f, 0.859f, 1.0f);


/**
 *
 */
Color::Color() : m_Red(1.0f), m_Green(1.0f), m_Blue(1.0f), m_Alpha(1.0f)
{
}


/**
 *
 */
Color::Color(float red, float green, float blue)  :
   m_Red(red), m_Green(green), m_Blue(blue), m_Alpha(1.0f)
{
}


/**
 *
 */
Color::Color(float red, float green, float blue, float alpha) :
   m_Red(red), m_Green(green), m_Blue(blue), m_Alpha(alpha)
{
}


/**
 *
 */
Color::Color(const Color &source) :
   m_Red(1.0f), m_Green(1.0f), m_Blue(1.0f), m_Alpha(1.0f)
{
   m_Red = source.m_Red;
   m_Green = source.m_Green;
   m_Blue = source.m_Blue;

   m_Alpha = source.m_Alpha;
}


/**
 *
 */
Color &Color::operator=(const Color &source)
{
   if (this != &source) {
      m_Red = source.m_Red;
      m_Green = source.m_Green;
      m_Blue = source.m_Blue;

      m_Alpha = source.m_Alpha;
   }

   return *this;
}


/**
 *
 */
ALLEGRO_COLOR Color::getAllegroColor() const
{
   ALLEGRO_COLOR result;
   result = al_map_rgba_f(m_Red, m_Green, m_Blue, m_Alpha);

   return result;
}


/**
 *
 */
Color::~Color()
{
}

// end of namespace
// ----------------
};

// end of namespace
// ----------------
};
