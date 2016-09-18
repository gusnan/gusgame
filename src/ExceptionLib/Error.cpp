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
#include <fstream>
#include <iostream>

#ifdef _WIN32
#include <windows.h>
#endif

#include "Exception.h"
#include "Error.h"

#include "LogLib.h"
using namespace Gus::LogLib;

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
	
Error *ErrorHandler::error = NULL;

/**
 *
 */
void ErrorHandler::initErrorHandler()
{
	error = NULL;
}

/**
 *
 */
void ErrorHandler::setError(Error *err)
{
	error = err;
}

/**
 *
 */
Error *ErrorHandler::getError()
{
	return error;
}

/**
 *
 */
void ErrorHandler::reportError(Exception& e)
{
	std::string st = e.getString();
	
	LOG(st);
	
#ifdef _WIN32
	MessageBox(NULL,(char*)(st.c_str()),(char*)(st.c_str()),MB_OK | MB_ICONWARNING);
#else
	std::cout << st << std::endl;
#endif
}

/**
 *
 */
Error::Error(Exception &e) : m_String(e.getString())
{
	//SetString(e.GetString());
}

/**
 *
 */
Error::Error(std::string st) : m_String(st)
{
	//SetString(st);
}

/**
 *
 */
Error::~Error()
{
}

/**
 *
 */
void Error::setString(std::string st)
{
	m_String = st;
}

/**
 *
 */
std::string Error::getString() const
{
	return m_String;
}

// end of namespace
// ----------------
};

// end of namespace
// ----------------
};
