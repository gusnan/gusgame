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
Bitmap::Bitmap() : m_AllegroBitmap(NULL), m_Size(-1,-1)
{
	setTarget(NULL);
}


/**
 *
 */
Bitmap::Bitmap(std::string filename) : m_AllegroBitmap(NULL), m_Size(-1,-1)
{
	std::string fixedFilename = FileHelper::getFilename(filename);
	
	m_AllegroBitmap = al_load_bitmap((char*)(fixedFilename.c_str()));
	
	if (!m_AllegroBitmap) {
		std::stringstream st;
		
		st << "Couldn't load image: " << filename;
		
		throw ExceptionLib::Exception(st.str());
	}
	
	m_Size.x=al_get_bitmap_width(m_AllegroBitmap);
	m_Size.y=al_get_bitmap_height(m_AllegroBitmap);
	
	setTarget(NULL);
}


/**
 *
 */
Bitmap::Bitmap(const Bitmap &source) : m_AllegroBitmap(NULL), m_Size(-1,-1)
{
	LOG("Copyconstructor...");
	
	if (source.m_AllegroBitmap)
		m_AllegroBitmap = al_clone_bitmap(source.m_AllegroBitmap);
		
	m_Size.x=source.m_Size.x;
	m_Size.y=source.m_Size.y;
	
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
		m_AllegroBitmap=NULL;
		
		if (source.m_AllegroBitmap) 
			m_AllegroBitmap = al_clone_bitmap(source.m_AllegroBitmap);
		
		m_Size.x=source.m_Size.x;
		m_Size.y=source.m_Size.y;
		
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
 *
 */
void Bitmap::setTarget(Bitmap *targetBitmap)
{
	if (!targetBitmap) {
		al_set_target_bitmap(al_get_backbuffer(GraphicsHandler::display));
	} else {
		al_set_target_bitmap(targetBitmap->getAllegroBitmap());
	}
}


/**
 *
 */
void Bitmap::blit(const Vector2d &position, float opacity)
{
	if (m_AllegroBitmap) {
		al_draw_bitmap(m_AllegroBitmap, (float)position.x, (float)position.y, 0);
	}
}


/**
 *
 */
void Bitmap::blit(const Rect &sourceRect, const Vector2d &position, float opacity)
{
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


// end of namespace
// ----------------
};

// end of namespace
// ----------------
};
