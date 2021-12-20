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
#include <string>
#include <vector>

#include "Exception.h"
#include "RuntimeError.h"
#include "FileNotFoundException.h"

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
FileNotFoundException::FileNotFoundException(std::string message) : RuntimeError(message)
{
}

/**
 *
 */
FileNotFoundException::~FileNotFoundException()
{
}
   
// end of namespace
// ----------------
};

// end of namespace
// ----------------
};
