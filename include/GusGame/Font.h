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

	Font(std::string filename, int size, bool useKerning);
	virtual ~Font();

	void draw(const Vector2d &position, std::string text, const Color &color);

protected:
};

// end of namespace
// ----------------
};

// end of namespace
// ----------------
};

#endif /*__HEADER_GUSGAME_FONT_*/
