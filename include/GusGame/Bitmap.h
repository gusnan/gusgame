/**
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
#ifndef __HEADER_BITMAP_
#define __HEADER_BITMAP_

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
class Bitmap
{
public:
	Bitmap();
	Bitmap(const Bitmap &source);

	Bitmap &operator=(const Bitmap &source);

	Bitmap(std::string filename);

	virtual ~Bitmap();

	Bitmap *makeCopy();

	ALLEGRO_BITMAP *getAllegroBitmap();

	Vector2d getSize() const;

	void setTarget(Bitmap *targetBitmap);

	void blit(const Vector2d &position,float opacity=1.0f);
	void blit(const Rect &sourceRect, const Vector2d &position, float opacity=1.0f);

	void blitCenter(const Rect &targetRect, float opacity=1.0f);
	void blitCenter(const Rect &sourceRect, const Rect &targetRect, float opacity=1.0f);

	void blitColor(const Vector2d &position, const Color &color, float opacity=1.0f);
	void blitCenterColor(const Rect &sourceRect, const Color &color, float opacity=1.0f);

	void drawPattern(const Rect &rect, float opacity=1.0f);

protected:

	ALLEGRO_BITMAP *m_AllegroBitmap;

	Vector2d m_Size;

};

// end of namespace
// ----------------
};

// end of namespace
// ----------------
};

#endif /*__HEADER_BITMAP_*/
