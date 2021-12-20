/**
 *
 *	This file is part of GusGame
 *	Copyright 2008,2009 Andreas Rönnquist
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
#ifndef __HEADER_STRING_HELPER_
#define __HEADER_STRING_HELPER_

/**
 *
 */
namespace Gus
{

/**
 *
 */
namespace StringHelper
{
   std::string upcase(std::string st);
   std::string lowercase(std::string st);

   //void ChangeCase(std::string& str,int(*)(int));
   void splitString(std::string instring,std::string& text,std::string& shortcut);

   int stringToInt(const std::string &st);

   std::string doubleParanthesis(std::string);

}

// end of namespace
// ----------------
}

#endif
