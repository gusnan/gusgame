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
#ifndef __HEADER_LOG_HANDLER_
#define __HEADER_LOG_HANDLER_

#include "DynamicLink.h"

#ifdef _DEBUG
#include <vector>
#endif

#define STLOG(a) if ((LogLib::log!=NULL) && (LogLib::LogHandler::logActive)) { LogLib::log->add(a.str());a.str(""); }

#define LOG(a) if ((LogLib::log!=NULL) && (LogLib::LogHandler::logActive)) LogLib::log->add(a)
#define LOGLINE() if ((LogLib::log!=NULL) && (LogLib::LogHandler::logActive)) LogLib::log->add("---------------------")

#ifdef _DEBUG
#define __INIT(a,b) a;LogHandler::addInit(b);
#define __DONE(a,b) a;LogHandler::doneInit(b);
#else
#define __INIT(a,b)
#define __DONE(a,b)
#endif

#define LOGOFF() LogLib::LogHandler::logOff();
#define LOGON() LogLib::LogHandler::logOn();

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
namespace LogHandler
{
#ifdef _DEBUG
	class StoreAlloc
	{
	public:
		StoreAlloc() : m_Value(0),m_Text("")
		{
		}

		StoreAlloc(std::string text) : m_Value(0),m_Text(text)
		{
		}

		StoreAlloc(std::string text,int value) : m_Value(value),m_Text(text)
		{
		}

		virtual ~StoreAlloc()
		{
		}

		int m_Value;
		std::string m_Text;
	};
#endif

#ifdef _DEBUG
	void GUSGAME_DLL initLog(std::string logfilename="log.txt",bool activateScreenLog=true);
#else
	void GUSGAME_DLL initLog(std::string logfilename="log.txt",bool activateScreenLog=false);
#endif
	void GUSGAME_DLL doneLog();

#ifdef _DEBUG
	void GUSGAME_DLL initAllocTrace();
	void GUSGAME_DLL doneAllocTrace();

	void GUSGAME_DLL addInit(std::string st);
	void GUSGAME_DLL doneInit(std::string);

	int GUSGAME_DLL getIndex(std::string st);

	void GUSGAME_DLL printList();

	extern std::vector<StoreAlloc> allocList;
	//extern std::map<std::string,int> allocList;
#endif

	void GUSGAME_DLL logOff();
	void GUSGAME_DLL logOn();

	extern bool fileLogActive;

	extern bool logTime;

	extern bool logActive;

};

extern GUSGAME_DLL Log *log;

// end of namespace
// ----------------
};

// end of namespace
// ----------------
};

#endif
