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
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <list>
#include <memory>

#include "GusGame.h"

using namespace Gus;

using namespace LogLib;
using namespace ExceptionLib;
using namespace GraphicsLib;
using namespace EventLib;

bool quit = false;


/**
 * This is an Eventhandler that takes care of the keyboard events, mouse motion
 *	events, and the Quit events. (This event is pushed when you press the close
 * window button for example)
 */
class ExampleEventHandler : public EventHandler
{
public:

   /**
    * Handle keyboard presses and releases
    */
   virtual bool handleKeyboard(KeyEvent &keyEvent) {

      // Is it the Escape Button that is pressed? - then quit
      if (keyEvent.getType() == KeyEventPressed) {
         if (keyEvent.getValue() == Key::Escape) {
            quit = true;
            return true;
         }
      }
      return false;
   }

   /**
    * handle the quit event
    */
   virtual void handleQuitEvent()
   {
      quit = true;
   }

   /**
    * Handle the system quit event. (This is called when the window close
    * button is pressed.) The System Quit event is separated from the standard
    * Quit event, so that you can separate for example window close button
    * presses from other quit events.
    */
   virtual void handleSystemQuitEvent()
   {
      quit = true;
   }

};


/**
 * main - the standard c++ program main entry point
 */
int main(int argc, char **argv)
{
   std::shared_ptr<EventHandler> eventHandler = std::shared_ptr<EventHandler>();

   try {
      // init the log - this function takes a string (the log file filename)
      // as indata, if none is inserted, "log.txt" is assumed. If you give the
      // empty string "" as filename for the log, no log will be used.
      //
      // The second indata is a boolean to determine to print the log to
      // std::cout or not in addition to to the file.
      LogHandler::initLog("log.txt", true);

      // init system stuff
      System::initSystem();

      // set up a screen with resolution of 640x480, and not fullscreen
      GraphicsHandler::instance().initGraphicsHandler();
      GraphicsHandler::instance().setGraphicsMode(Vector2d(640, 480), false);

      // set a window title
      GraphicsHandler::instance().setWindowTitle("GusGame Example 7");

      // Create an EventHandler for our "custom" events from the class
      // that is defined above
      eventHandler = std::shared_ptr<EventHandler>(new ExampleEventHandler());

      EventSystem::initEventSystem();

      // set the used EventHandler to the one we just created.
      EventSystem::addEventHandler(eventHandler);
      //EventSystem::addEventHandler(eventHandler);

      // We need to init the primitives unit
      Primitives::initPrimitives();


   }
   catch (Exception &e)
   {
      // If we get any problems with the code in the throw block, it will be
      // caught here
      std::cerr << "Exception: " << e.getString() << std::endl;

      return EXIT_FAILURE;
   }

   LOG("Enter main loop.");

   // the main loop
   do {
      // Update the timer
      Timer::updateFrame();

      // Handle events (see the class just above this main
      EventSystem::handleEvents();

      // Clear the screen every sync
      GraphicsHandler::instance().clearScreen();

      Primitives::line(Vector2d(100, 100), Vector2d(200, 250), Color(1.0f, 1.0f, 0.0f), 3.0f);

      Primitives::rect(Rect(120, 120, 200, 150), Color(1.0f, 0.0f, 0.0f), 1.0f);

      // Update the screen
      GraphicsHandler::instance().updateScreen();
   } while(!quit);


   Primitives::donePrimitives();

   EventSystem::doneEventSystem();

   GraphicsHandler::instance().doneGraphicsHandler();

   // done with system stuff
   System::doneSystem();

   // done with the Log
   LogHandler::doneLog();

   return EXIT_SUCCESS;
}
