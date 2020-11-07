/**
 *
 *	This file is part of GusGame.
 *	Copyright 2011-2020 Andreas Rönnquist
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
#include <fstream>
#include <iostream>

#include "ExceptionLib.h"
using namespace Gus::ExceptionLib;

#include "Log.h"
#include "LogHandler.h"

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
Log GUSGAME_DLL *log = nullptr;

#ifdef _ENABLE_ALLOC_TRACE
std::vector<LogHandler::StoreAlloc> LogHandler::allocList;
#endif
	
bool LogHandler::fileLogActive = true;

bool LogHandler::logActive = true;

bool LogHandler::logTime = false;
	

/**
 *
 */
void GUSGAME_DLL LogHandler::initLog(std::string filename, bool activateScreenLog)
{
	fileLogActive = false;
	
	try {
		if (filename != "") {
			fileLogActive = true;
			log = new Log(filename, fileLogActive, activateScreenLog);
		}
	}
	catch (Exception)
	{
		throw;
	}
#ifdef _ENABLE_ALLOC_TRACE
	initAllocTrace();
#endif
	
	
}

/**
 *
 */
void GUSGAME_DLL LogHandler::doneLog()
{
#ifdef _ENABLE_ALLOC_TRACE
	doneAllocTrace();
#endif

   if (log != nullptr) {
      delete log;
   }
	log = nullptr;
}


/**
 *
 */
void GUSGAME_DLL LogHandler::logOn()
{
	logActive = true;
}


/**
 *
 */
void GUSGAME_DLL LogHandler::logOff()
{
	logActive = false;
}

#ifdef _ENABLE_ALLOC_TRACE
/**
 *
 */
void GUSGAME_DLL LogHandler::initAllocTrace()
{
	allocList.clear();
}

/**
 *
 */
void GUSGAME_DLL LogHandler::doneAllocTrace()
{
	printList();
}

/**
 *
 */
void GUSGAME_DLL LogHandler::addInit(std::string st)
{
	// Get the number

	int nr = getIndex(st);

	// the string is in the list
	if (nr != -1) {
		allocList[nr].m_Value++;
	} else {
		// string not in list
		StoreAlloc ny(st);
		ny.m_Value++;
		allocList.push_back(ny);
	}
}

/**
 *
 */
void GUSGAME_DLL LogHandler::doneInit(std::string st)
{
	int nr = getIndex(st);
	if (nr != -1) {
		allocList[nr].m_Value--;
	} else {
		StoreAlloc ny;
		ny.m_Value--;
		allocList.push_back(ny);
	}
}

/**
 *
 */
int GUSGAME_DLL LogHandler::getIndex(std::string st)
{
	int nr = -1;

	if (!allocList.empty()) {
		int counter = 0;
		for(std::vector<LogHandler::StoreAlloc>::iterator iter = allocList.begin(); iter != allocList.end();) {
			StoreAlloc current = (*iter);

			if (current.m_Text == st) nr = counter;

			++iter;
			++counter;
		}
	}

	return nr;
}

/**
 *
 */
void GUSGAME_DLL LogHandler::printList()
{
	if (!allocList.empty()) {
		for(std::vector<LogHandler::StoreAlloc>::iterator iter = allocList.begin(); iter != allocList.end();)
		{
			StoreAlloc current = (*iter);

			if (current.m_Value != 0) {
				std::cout << current.m_Text << ":" << current.m_Value << std::endl;
			}

			++iter;
		}
	}
}
#endif

// end of namespace
// ----------------
}

// end of namespace
// ----------------
};
