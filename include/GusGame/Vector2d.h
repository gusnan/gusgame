/**
 *
 *	This file is part of GusGame.
 *	Copyright 2011 Andreas Rönnquist
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
#ifndef __HEADER_VECTOR2D_
#define __HEADER_VECTOR2D_

#include <iostream>
#include <fstream>

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
//template <class Type>
class Vector2d
{
public:
   /**
    *
    */
   Vector2d() : x(-1), y(-1)
   {
      //SetPosition(-1,-1);
   }

   /**
    *
    */
   Vector2d(int xpos,int ypos) : x(xpos), y(ypos)
   {
      //x=xpos;
      //y=ypos;
      //SetPosition(xpos,ypos);
   }

   /**
    *
    */
   Vector2d(const Vector2d &source) : x(0), y(0)
   {
      if (this != &source) {
         this->x = source.x;
         this->y = source.y;
      }
   }

   /**
    *
    */
   Vector2d& operator=(const Vector2d& source)
   {
      x = source.x;
      y = source.y;

      return *this;
   }


   /**
    *
    */
   Vector2d operator*(const Vector2d& source) const
   {
      Vector2d res(*this);

      res.x = x * source.x;
      res.y = y * source.y;

      return res;
   }

   /**
    *
    */
   Vector2d operator*(const int a) const
   {
      Vector2d res(*this);

      res.x = x * a;
      res.y = y * a;

      return res;
   }




   /**
    *
    */
   Vector2d operator-(const Vector2d& source) const
   {
      Vector2d res(*this);

      res.x = x - source.x;
      res.y = y - source.y;

      return res;
   }


   /**
    *
    */
   void operator*=(const Vector2d& source)
   {

   //	Vector2d res(*this);

      this->x = x * source.x;
      this->y = y * source.y;

      //return *this;
   }

   /**
    *
    */
   Vector2d operator+=(const Vector2d& source)
   {

      Vector2d res(*this);

      this->x = x + source.x;
      this->y = y + source.y;

      return *this;
   }

   /**
    *
    */
   Vector2d operator+(const Vector2d& source) const
   {

      Vector2d res = Vector2d(*this);

      res.x = x + source.x;
      res.y = y + source.y;

      return res;
   }

   /*
   Vector2d operator+(Vector2d a,Vector2d b)
   {
      Vector2d r=a;
      return r+=b;

   }
   */


   /**
    *
    */
   void operator-=(const Vector2d& source)
   {
      //Vector2d res(*this);

      this->x = x - source.x;
      this->y = y - source.y;

      //return *this; //*this;
   }


   /**
    *
    */
   bool operator==(const Vector2d& source) const
   {
      bool res = false;

      if ((this->x == source.x) && (this->y == source.y)) {
         res = true;
      }

      return res;
   }


   /**
    *
    */
   bool operator!=(const Vector2d& source) const
   {
      bool res = false;

      if ((this->x != source.x) || (this->y != source.y)) {
         res = true;
      }

      return res;

      //return (!(operator==(source)));
   }


   /**
    *
    */
   Vector2d *makeCopy()
   {
      return new Vector2d(*this);
   }

   /**
    *
    */
   virtual ~Vector2d()
   {

   }

   /**
    *
    */
   void setPosition(int xpos,int ypos)
   {
      x = xpos;
      y = ypos;
   }

   /**
    *
    */
   std::string getString()
   {
      std::stringstream stringStream;

      stringStream << "Vector2d: xpos:" << x << " ypos:" << y <<
            " Ptr:" << (this);

      return stringStream.str();
   }

   /**
    *
    */
   std::string getShortString()
   {
      std::stringstream stringStream;

      stringStream << x << "," << y;

      return stringStream.str();
   }



   /**
    *
    */
   bool inRange(Vector2d pos) const
   {
      bool result = false;

      if ((pos.x == x + 1) && (pos.y == y)) result = true;
      if ((pos.x == x - 1) && (pos.y == y)) result = true;
      if ((pos.x == x) && (pos.y == y + 1)) result = true;
      if ((pos.x == x) && (pos.y == y - 1)) result = true;

      return result;

   }


   /**
    *	to get the positions next to the actual one:
    */
   Vector2d oneRight()
   {
      return Vector2d(x + 1, y);
   }

   /**
    *
    */
   Vector2d oneLeft()
   {
      return Vector2d(x - 1, y);
   }

   /**
    *
    */
   Vector2d oneUp()
   {
      return Vector2d(x, y - 1);
   }

   /**
    *
    */
   Vector2d oneDown()
   {
      return Vector2d(x, y + 1);
   }

   friend std::ostream &operator<<(std::ostream &stream, Vector2d vec) {
      stream << vec.x << "," << vec.y;

      return stream;
   }


   int x, y;
};

// end of namespace
// ----------------
};



// end of namespace
// ----------------
};

#endif /*VECTOR2D_H_*/

