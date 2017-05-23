/**
 *
 *	This file is part of GusGame
 *	Copyright (C) 2013-2017 Andreas Rönnquist
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
#ifndef __HEADER_PRIMITIVES_
#define __HEADER_PRIMITIVES_


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
namespace Primitives
{
	void initPrimitives();
	void donePrimitives();

	void line(const Vector2d &sourcePoint, const Vector2d &targetPoint, const Color &color, float thickness = 1.0f);

	void rect(const Rect &rect, const Color &color, float thickness = 1.0f);
	void rectFill(const Rect &rect, const Color &color);

};

// end of namespace
// ----------------
};

// end of namespace
// ----------------
};

#endif /*__HEADER_PRIMITIVES_*/
