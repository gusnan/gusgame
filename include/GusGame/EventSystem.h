/**
 *
 *	This file is part of GusGame
 *	Copyright (C) 2013-2014 Andreas Rönnquist
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
#ifndef __HEADER_EVENT_SYSTEM_
#define __HEADER_EVENT_SYSTEM_

/**
 *
 */
namespace Gus
{

/**
 *
 */
namespace EventLib
{

/**
 *
 */
namespace EventSystem
{
   void initEventSystem();
   void doneEventSystem();

   void addEventHandler(EventHandlerPtr eventHandler);
   void removeEventHandler(const EventHandlerPtr &eventHandler);

   void handleEvents();
   bool doHandleEvents(ALLEGRO_EVENT ev, EventHandlerPtr eventHandler);

   void printEventHandlers();

   extern ALLEGRO_EVENT_QUEUE *eventQueue;

   //extern EventHandler *eventHandler;

   //ALLEGRO_EVENT_SOURCE *getUserEventSource();

   extern std::list<EventHandlerPtr> *listOfEventHandlers;

   extern ALLEGRO_EVENT_SOURCE userEventSource;

   extern std::list<UserEvent*> *listDelayedEvents;


   extern std::list<EventHandlerPtr> *handlersToRemove;

   extern bool inEventLoop;

};

// end of namespace
// ----------------
};

// end of namespace
// ----------------
};

#endif /*__HEADER_EVENT_SYSTEM_*/
