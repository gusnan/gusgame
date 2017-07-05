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
#include <string>
#include <sstream>
#include <list>

#include "Library.h"

#include "ExceptionLib.h"

#include "Vector2d.h"
#include "Rect.h"

#include "Color.h"
#include "Bitmap.h"

#include "GraphicsHandler.h"

#include "FileHelper.h"

#include "LogLib.h"


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
Bitmap::Bitmap() : m_AllegroBitmap(NULL), m_Size(-1, -1), m_TargetBitmap(NULL)
{
	setTarget(NULL);
}


/**
 *
 */
Bitmap::Bitmap(const Vector2d &size) : m_Size(size.x, size.y), m_TargetBitmap(NULL)
{
	m_AllegroBitmap = al_create_bitmap(size.x, size.y);
	
	setTarget(NULL);
}


/**
 *
 */
Bitmap::Bitmap(std::string filename) : m_AllegroBitmap(NULL), m_Size(-1, -1), m_TargetBitmap(NULL)
{
	std::string fixedFilename = FileHelper::getFilename(filename);

	m_AllegroBitmap = al_load_bitmap((char*)(fixedFilename.c_str()));

	if (!m_AllegroBitmap) {
		std::stringstream st;

		st << "Couldn't load image: " << filename;

		throw ExceptionLib::Exception(st.str());
	}

	m_Size.x = al_get_bitmap_width(m_AllegroBitmap);
	m_Size.y = al_get_bitmap_height(m_AllegroBitmap);

	setTarget(NULL);
}


/**
 *
 */
Bitmap::Bitmap(const Bitmap &source) : m_AllegroBitmap(NULL), m_Size(-1, -1), m_TargetBitmap(NULL)
{
	LOG("Copyconstructor...");

	if (source.m_AllegroBitmap)
		m_AllegroBitmap = al_clone_bitmap(source.m_AllegroBitmap);

	m_Size.x = source.m_Size.x;
	m_Size.y = source.m_Size.y;

	setTarget(NULL);
}


/**
 *
 */
Bitmap &Bitmap::operator=(const Bitmap &source)
{
	if (this != &source) {
		if (m_AllegroBitmap) {
			al_destroy_bitmap(m_AllegroBitmap);
		}
		m_AllegroBitmap = NULL;

		if (source.m_AllegroBitmap)
			m_AllegroBitmap = al_clone_bitmap(source.m_AllegroBitmap);

		m_Size.x = source.m_Size.x;
		m_Size.y = source.m_Size.y;

		setTarget(NULL);
	}

	return *this;
}


/**
 *
 */
Bitmap::~Bitmap()
{
	if (m_AllegroBitmap) {
		al_destroy_bitmap(m_AllegroBitmap);
	}
}


/**
 *
 */
Bitmap *Bitmap::makeCopy()
{
	return new Bitmap(*this);
}


/**
 *
 */
ALLEGRO_BITMAP *Bitmap::getAllegroBitmap()
{
	return m_AllegroBitmap;
}


/**
 *
 */
Vector2d Bitmap::getSize() const
{
	return m_Size;
}


/**
 * setTarget
 *   Set the target to NULL to draw directly to screen.
 */
void Bitmap::setTarget(Bitmap *inTargetBitmap)
{
	if (!inTargetBitmap) {
		al_set_target_bitmap(al_get_backbuffer(GraphicsHandler::display));
	} else {
		al_set_target_bitmap(inTargetBitmap->getAllegroBitmap());
	}
	m_TargetBitmap = inTargetBitmap;
}


/**
 *
 */
void Bitmap::blit(const Vector2d &position, float opacity)
{
	if (m_AllegroBitmap) {
		// al_draw_bitmap(m_AllegroBitmap, (float)position.x, (float)position.y, 0);

		float multiX = GraphicsHandler::zoomX;
		float multiY = GraphicsHandler::zoomY;

		if (m_TargetBitmap) {
			multiX = 1.0f;
			multiY = 1.0f;
		}

		float rpx = (float)position.x * (float)multiX;
		float rpy = (float)position.y * (float)multiY;

		float rxs = (float)m_Size.x * (float)multiX;
		float rys = (float)m_Size.y * (float)multiY;

		al_draw_scaled_bitmap(m_AllegroBitmap, 0, 0, m_Size.x, m_Size.y, rpx, rpy,
				rxs, rys, 0/*al_flags*/);
	}
}


/**
 *
 */
void Bitmap::blitFlipped(const Vector2d &position, FlipDirection inFlags, float opacity)
{
	if (m_AllegroBitmap) {

		int al_flags = 0;

		switch(inFlags) {
		case FlipNone:
			al_flags = 0;
			break;
		case FlipHorizontal:
			al_flags = ALLEGRO_FLIP_HORIZONTAL;
			break;
		case  FlipVertical:
			al_flags = ALLEGRO_FLIP_VERTICAL;
			break;
		};

		// al_draw_bitmap(m_AllegroBitmap, (float)position.x, (float)position.y, al_flags);


		float multiX = GraphicsHandler::zoomX;
		float multiY = GraphicsHandler::zoomY;

		if (m_TargetBitmap) {
			multiX = 1.0f;
			multiY = 1.0f;
		}

		float rpx = (float)position.x * (float)multiX;
		float rpy = (float)position.y * (float)multiY;

		float rxs = (float)m_Size.x * (float)multiX;
		float rys = (float)m_Size.y * (float)multiY;

		al_draw_scaled_bitmap(m_AllegroBitmap, 0, 0, m_Size.x, m_Size.y, rpx, rpy,
				rxs, rys, al_flags);
	}
}


/**
 *
 */
void Bitmap::blitFlipped(const Rect &rect, FlipDirection inFlags, float opacity)
{
	if (m_AllegroBitmap) {

		int al_flags = 0;

		switch(inFlags) {
		case FlipNone:
			al_flags = 0;
			break;
		case FlipHorizontal:
			al_flags = ALLEGRO_FLIP_HORIZONTAL;
			break;
		case  FlipVertical:
			al_flags = ALLEGRO_FLIP_VERTICAL;
			break;
		};

		float multiX = GraphicsHandler::zoomX;
		float multiY = GraphicsHandler::zoomY;

		if (m_TargetBitmap) {
			multiX = 1.0f;
			multiY = 1.0f;
		}

		float rpx = (float)rect.position.x * (float)multiX;
		float rpy = (float)rect.position.y * (float)multiY;

		float rxs = (float)rect.size.x * (float)multiX;
		float rys = (float)rect.size.y * (float)multiY;

		al_draw_scaled_bitmap(m_AllegroBitmap, 0, 0, m_Size.x, m_Size.y, rpx, rpy, rxs, rys, al_flags);
	}
}


/**
 *
 */
void Bitmap::blit(const Rect &targetRect, float opacity)
{
	if (m_AllegroBitmap) {
		
		float multiX = GraphicsHandler::zoomX;
		float multiY = GraphicsHandler::zoomY;

		if (m_TargetBitmap) {
			multiX = 1.0f;
			multiY = 1.0f;
		}

		float rpx = (float)targetRect.position.x * (float)multiX;
		float rpy = (float)targetRect.position.y * (float)multiY;

		float rxs = (float)targetRect.size.x * (float)multiX;
		float rys = (float)targetRect.size.y * (float)multiY;

		al_draw_scaled_bitmap(m_AllegroBitmap,
			0, 0, m_Size.x, m_Size.y, rpx, rpy, rxs, rys, 0);

		/*
		void al_draw_scaled_bitmap(ALLEGRO_BITMAP *bitmap,
   float sx, float sy, float sw, float sh,
   float dx, float dy, float dw, float dh, int flags)
		*/
	}
}


/**
 *
 */
void Bitmap::blit(const Rect &sourceRect, const Vector2d &position, FlipDirection inFlip, float opacity)
{
	if (m_AllegroBitmap) {
		// al_draw_bitmap(m_AllegroBitmap, (float)position.x, (float)position.y, 0);

		int spx = sourceRect.position.x;
		int spy = sourceRect.position.y;

		float sxs = sourceRect.size.x;
		float sys = sourceRect.size.y;

		float multiX = GraphicsHandler::zoomX;
		float multiY = GraphicsHandler::zoomY;

		if (m_TargetBitmap) {
			multiX = 1.0f;
			multiY = 1.0f;
		}

		float txs = (float)((float)sourceRect.size.x * (float)multiX);
		float tys = (float)((float)sourceRect.size.y * (float)multiY);

		float tpx = (float)((float)position.x * (float)multiX);
		float tpy = (float)((float)position.y * (float)multiY);

		int al_flags = 0;

		switch(inFlip) {
		case FlipNone:
			al_flags = 0;
			break;
		case FlipHorizontal:
			al_flags = ALLEGRO_FLIP_HORIZONTAL;
			break;
		case  FlipVertical:
			al_flags = ALLEGRO_FLIP_VERTICAL;
			break;
		};

		// Rect rect(Vector2d(rpx, rpy), Vector2d(rxs, rys));

		al_draw_scaled_bitmap(m_AllegroBitmap, spx, spy, sxs, sys, tpx, tpy,
				txs, tys, al_flags);
	}	
}


/**
 *
 */
void Bitmap::blitColor(const Vector2d &position, const Color &color, float opacity)
{
}


/**
 *
 */
void Bitmap::blitCenterColor(const Rect &sourceRect, const Color &color, float opacity)
{

}


/**
 *
 */
void Bitmap::blitCenter(const Rect &targetRect, float opacity)
{
}


/**
 *
 */
void Bitmap::blitCenter(const Rect &sourceRect, const Rect &targetRect, float opacity)
{
}


/**
 *
 */
void Bitmap::drawPattern(const Rect &rect, float opacity)
{

}


/**
 *
 */


// end of namespace
// ----------------
};

// end of namespace
// ----------------
};
