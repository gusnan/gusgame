/**
 *
 *	This file is part of GusGame.
 *	Copyright 2011-2017 Andreas Rönnquist
 *
 *	GusGame is free software: you can redistribute it and/or modify
 *	it under the terms of the GNU Lesser General Public License as published by
 *	the Free Software Foundation, either version 3 of the License, or
 *	(at your option) any later version.
 *
 *	GusGame is distributed in the hope that it will be useful,
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *	GNU Lesser General Public License for more details.
 *
 *	You should have received a copy of the GNU Lesser General Public License
 *	along with GusGame.  If not, see <http://www.gnu.org/licenses/>.
 *
 */
#ifndef __HEADER_GUS_RECT_
#define __HEADER_GUS_RECT_

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

//class Vector2d<Type>;

/**
 *	Rect
 */
//template <class Type>
class Rect
{
public:

	/**
	 *
	 */
	Rect() : position(Vector2d()), size(Vector2d())
	{
	}

	/**
	 *
	 */
	Rect(const Vector2d& pos, const Vector2d& siz) : position(pos), size(siz)
	//Rect(Vector2d<Type> pos,Vector2d<Type> siz)
	{
		//SetPosition(pos);
		//position=pos;
		//SetSize(siz);
		//size=siz;

	}

	/**
	 *
	 */
	Rect(int XPos, int YPos, int XSize, int YSize) : position(Vector2d(XPos, YPos)), size(Vector2d(XSize, YSize))
	{
		//position=Vector2d<Type>(XPos,YPos);
		//position.SetPosition(XPos,YPos);

		//size.SetPosition(XSize,YSize);
		//size=Vector2d<Type>(XSize,YSize);
	}

	/**
	 *
	 */
	Rect(const Rect &rect) : position(rect.position), size(rect.size)
	{
		//position=rect.position;
		//size=rect.size;
	}


	/**
	 *
	 */
	Rect& operator=(const Rect& sourceRect)
	{
		if (this != &sourceRect) {
			position = sourceRect.position;
			size = sourceRect.size;

		}

		return *this;
	}

	/**
	 *
	 */
	Rect operator+(const Vector2d& vect)
	{
		//Rect result(*this);

		/*
		Vector2d<Type> position=GetPosition();
		Vector2d<Type> size=GetSize();
		*/

		/*
		int x,y;
		x=position.x();
		y=position.y;

		int x2=(int)vect.x();
		int y2=vect.y;
		*/
		Vector2d pos = position;

		pos.x += vect.x;
		pos.y += vect.y;

		//position.setPosition(x+vect.x(),y+vect.y);

		Rect result = Rect(pos,size);

		return result;

		/*
		Vector2d res(*this);

		res.m_Xpos=m_Xpos+source.m_Xpos;
		res.m_Ypos=m_Ypos+source.m_Ypos;

		return res;
		*/
	}


	/**
	 *
	 */
	bool operator==(const Rect& sourceRect)
	{
		bool result = false;

		bool checkPos = false, checkSize = false;

		if (position == sourceRect.position) checkPos = true;
		if (size == sourceRect.size) checkSize = true;

		if (checkPos && checkSize) result = true;

		return result;
	}


	/**
	 *
	 */
	virtual ~Rect()
	{

	}
/*
	Vector2d<Type> GetPosition()
	{
		return position;
	}

	Vector2d<Type> GetSize()
	{
		return size;
	}


	void SetPosition(Vector2d<Type> p)
	{
		position=p;
	}

	void SetSize(Vector2d<Type> s)
	{
		size=s;
	}
	*/


	/**
	 *
	 */
	std::string GetString()
	{
		std::stringstream stringStream;

		stringStream << "Rect, pos: " << position.x << "," << position.y <<
				" , size: " << size.x << "," << size.y; // <<
				//" , ptr: " << (int)(this);

		return stringStream.str();
	}


	/**
	 *
	 */
	bool isPointOver(Vector2d point)
	{
		bool res = false;

		/*
		if (*this==fullScreenRect) {
			return true;
		}
		*/

		int px = point.x;
		int py = point.y;

		int rpx = position.x;
		int rpy = position.y;

		int rxs = size.x;
		int rys = size.y;

		if ((px >= rpx) && (py >= rpy) && (px < rpx + rxs) && (py < rpy + rys)) res = true;

		return res;
	}

	/**
	 *
	 */
	bool isPointOverTranslated(Vector2d point, float zoomX, float zoomY)
	{
		bool res = false;

		/*
		if (*this==fullScreenRect) {
			return true;
		}
		*/

		int px = point.x;
		int py = point.y;

		int rpx = (float)position.x * (float)zoomX;
		int rpy = (float)position.y * (float)zoomY;

		int rxs = (float)size.x * (float)zoomX;
		int rys = (float)size.y * (float)zoomY;

		if ((px >= rpx) && (py >= rpy) && (px < rpx + rxs) && (py < rpy + rys)) res = true;

		return res;
	}


	/**
	 *	getCenter
	 *	returns the center position of the rectangle
	 */
	Vector2d getCenter()
	{
		int x = position.x;
		int y = position.y;

		int xs = size.x;
		int ys = size.y;

		Vector2d result(x + xs / 2, y + ys / 2);

		return result;
	}

	/**
	 *
	 */
	void setPosition(Vector2d pos)
	{
		position = pos;
	}

	/**
	 *	setCenter
	 */
	void setCenter(Vector2d pos)
	{
		int xs = size.x;
		int ys = size.y;

		Vector2d newPosition = Vector2d(pos.x - (xs / 2), pos.y - (ys / 2));

		//SetPosition(newPosition);
		position = newPosition;
	}

	/**
	 *
	 */
	int getXCenter()
	{
		return position.x + (size.x / 2);
	}

	Vector2d position;
	Vector2d size;

};

extern const Rect fullScreenRect;


inline bool operator==(Rect &rect1, const Rect &rect2)
{
	bool result = true;
	
	if (rect1.position != rect2.position) result = false;
	if (rect1.size != rect2.size) result = false;
	
	return result;
}

inline bool operator!=(Rect &rect1, const Rect &rect2)
{
	return !operator==(rect1, rect2);
}

// end of namespace
// ----------------
}

// end of namespace
// ----------------
};

#endif /*__HEADER_GUS_RECT_*/

