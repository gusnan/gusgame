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
#include <boost/shared_ptr.hpp>

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <list>

#include "GusGame.h"

using namespace Gus;

using namespace LogLib;
using namespace ExceptionLib;
using namespace GraphicsLib;

/**
 * main - the standard c++ program main entry point
 */
int main(int argc,char **argv)
{
	try {
		// init the log - this function takes a string (the log file filename) as indata,
		// if none is inserted, "log.txt" is assumed. If you give the empty string ""
		// as filename for the log, no log will be used.
		//
		// The second indata is a boolean to determine to print the log to std::cout
		// or not.
		LogHandler::initLog("log.txt",true);

		// init system stuff
		System::initSystem();

		// Get and print the versions of SDL that we are using
		std::stringstream st;

#ifdef GUSGAME_USE_SDL
		st << "SDL Compile time version:" << System::instance()->getSDLCompileTimeVersion();

		// Print the info to the screen
		std::cout << st.str() << std::endl;
		// and then to the logfile
		STLOG(st);

		st << "SDL Runtime version:" << System::instance()->getSDLRunTimeVersion();

		// Print the info to the screen
		std::cout << st.str() << std::endl;
		// and then to the logfile
		STLOG(st);
#endif

		// Get the GusGui version:
		st << "GusGui version: " << System::getGusGameVersion();

		// print it to the screen
		std::cout << st.str() << std::endl;
		// and to the logfile
		STLOG(st);

		// we need to init the graphics handler to get the OpenGL version
		GraphicsHandler::initGraphicsHandler();

				// we need to init a graphics screen to get the OpenGL information
		GraphicsHandler::setGraphicsMode(Vector2d(640,480),false);

		// print the openGL version
		st << "OpenGL version: " << GraphicsHandler::getOpenGLVersionString();

		// print it to the screen
		std::cout << st.str() << std::endl;
		// and to the logfile
		STLOG(st);


	}
	catch (Exception &e)
	{
		// If we get any problems with the code in the throw block, it will be
		// caught here
		std::cerr << "Exception: " << e.getString() << std::endl;

		return EXIT_FAILURE;
	}

	GraphicsHandler::doneGraphicsHandler();

	// done with system stuff
	System::doneSystem();

	// done with the Log
	LogHandler::doneLog();

	return EXIT_SUCCESS;
}
