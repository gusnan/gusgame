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
#ifndef __HEADER_STRING_TO_INT_EXCEPTION_
#define __HEADER_STRING_TO_INT_EXCEPTION_

/**
 *
 */
namespace Gus
{

/**
 *
 */
namespace ExceptionLib
{

/**
 *
 */
class StringToIntException : public RuntimeError
{
public:
   StringToIntException();
   StringToIntException(std::string message);
   virtual ~StringToIntException();
protected:
};

// end of namespace
// ----------------
};

// end of namespace
// ----------------
};

#endif /*__HEADER_STRING_TO_INT_EXCEPTION_*/
