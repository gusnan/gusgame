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
#ifndef __HEADER_LOG_
#define __HEADER_LOG_

#include "DynamicLink.h"

/**
 *
 */
#include <string>
#include <fstream>

/**
 *
 */
namespace Gus
{

/**
 *
 */
namespace LogLib
{

/**
 *
 */
class Log
{
public:

	GUSGAME_DLL Log(std::string fileName,bool activeFilelog,bool activeScreenLog);
	virtual GUSGAME_DLL ~Log();

	void GUSGAME_DLL add(std::string message);
	void GUSGAME_DLL add(std::stringstream message);
	void GUSGAME_DLL addLine();

	void GUSGAME_DLL addIndent();
	void GUSGAME_DLL removeIndent();

	std::string GUSGAME_DLL getTime();
	std::string GUSGAME_DLL getDate();

private:
	void openFile();
	void closeFile();

protected:

	std::ofstream m_File;

	bool m_FileLogActive;
	bool m_ScreenLogActive;

	int m_Indent;

	std::string m_Filename;

};

// end of namespace
// ----------------
}

// end of namespace
// ----------------
};

#endif



