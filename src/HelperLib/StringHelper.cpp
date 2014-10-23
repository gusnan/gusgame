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
#include <string>
#include <sstream>
#include <iostream>

#include "ExceptionLib.h"
//using namespace ExceptionLib;

#include "StringHelper.h"

/**
 *	String Helper library
 */
namespace Gus
{

/**
 *	Upcase
 */
std::string StringHelper::upcase(std::string str)
{

	/* --- Doesn't work on Visual C++ 2008 Express
	std::transform(str.begin(),
				str.end(),
				str.begin(),
				(int(*)(int)) std::toupper);
*/
	std::string res=str;

	for (int co=0;co<(int)str.length();co++) {
		char ch=str[co];
		res[co]=toupper(ch);
	}

	return res;
}

/**
 *	Lowercase
 */
std::string StringHelper::lowercase(std::string str)
{
	/* --- Doesn't work on Visual C++ 2008 Express
	std::transform(str.begin(),
				str.end(),
				str.begin(),
				(int(*)(int)) std::tolower);
	*/

	std::string res=str;

	for (int co=0;co<(int)str.length();co++) {
		char ch=str[co];
		res[co]=tolower(ch);
	}

	return res;
}


/**
 *
 */
void StringHelper::splitString(std::string instring,std::string& text,std::string& shortcut)
{
	text=instring;
	shortcut="";

	//bool containsParanthesis=false;

	int startPar=-1;

	int len=(int)instring.length();

	for (int co=0;co<len;co++) {
		if (instring[co]=='(') {
			//containsParanthesis=true;
			startPar=co;
			//LOG("Contains Paranthesis...");
		}
	}

	int posEndPar=-1;

	for (int co=0;co<(int)instring.length();co++) {
		if (instring[co]==')') {
			posEndPar=co; //containsParanthesis=true;
			//std::cout << "Contains Parathesis!" << std::endl;
		}
	}

	if (posEndPar!=-1) {
		if (startPar!=-1) {
			text=instring.substr(0,startPar);
			shortcut=instring.substr(startPar+1,len-(startPar+2));
		}
	}
}

/**
 *
 */
int StringHelper::stringToInt(const std::string &str)
{
	std::istringstream i(str);
	int res;

	if (!(i>>res))
		throw ExceptionLib::StringToIntException();

	return res;
}

/**
 *
 */
std::string StringHelper::doubleParanthesis(std::string st)
{
	std::string result="";



	for (int co=0;co<(int)st.length();co++) {
		char ch=st[co];

		switch (ch) {
			case '[':
			case ']':
				result+=ch;
		}

		result+=ch;

	}
	return result;
}

// end of namespace
// ----------------
}
