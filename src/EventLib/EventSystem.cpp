/**
 *	This file is part of GusGame
 *	Copyright (C) 2013 Andreas Rönnquist
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
#include "boost/shared_ptr.hpp"

#include <sstream>
#include <list>

#include "Library.h"

#include "Vector2d.h"
#include "Rect.h"

#include "Exception.h"

#include "LogLib.h"

#include "ActiveEvent.h"
#include "KeyEvent.h"
#include "SystemQuitEvent.h"
#include "UserEvent.h"
#include "MouseButtonEvent.h"
#include "MouseMotionEvent.h"

#include "EventHandler.h"

#include "EventSystem.h"

#include "Color.h"
#include "Bitmap.h"

#include "GraphicsHandler.h"

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
ALLEGRO_EVENT_QUEUE *EventSystem::eventQueue=NULL;
//EventHandler *EventSystem::eventHandler=NULL;
ALLEGRO_TIMEOUT timeout;

ALLEGRO_EVENT_SOURCE userEventSource;
	
std::list<EventHandlerPtr> *EventSystem::listOfEventHandlers=NULL;

/**
 *
 */
void EventSystem::initEventSystem()
{
	LOG("initEventSystem");
	
	al_init_user_event_source(&userEventSource);

	eventQueue = al_create_event_queue();
	if (!eventQueue) {
		throw ExceptionLib::Exception("Could crate event queue!");
	}
	
	listOfEventHandlers = new std::list<EventHandlerPtr>;
	
	listOfEventHandlers->clear();
	
	al_register_event_source(eventQueue, al_get_display_event_source(GraphicsLib::GraphicsHandler::display));
	
	al_register_event_source(eventQueue, al_get_keyboard_event_source());
	
	al_register_event_source(eventQueue, al_get_mouse_event_source());
	
	al_register_event_source(eventQueue, &userEventSource);
	
	al_init_timeout(&timeout, 0.06);
}


/**
 *
 */
void EventSystem::doneEventSystem()
{
	std::list<EventHandler*>::iterator iter;
	
	al_destroy_user_event_source(&userEventSource);
	
	if (eventQueue) {
		al_destroy_event_queue(eventQueue);
		eventQueue = NULL;
	}
	
	if (listOfEventHandlers) {
		
		// Don't delete the eventhandlers in the list here, you'll have to do
		// it by hand
		/*
		for (iter = listOfEventHandlers->begin(); iter != listOfEventHandlers->end();) {
			delete (*iter);
			++iter;
		}
		*/
		
		delete listOfEventHandlers;
		listOfEventHandlers=0;
	}
}


/**
 *
 */
void EventSystem::addEventHandler(EventHandlerPtr inEventHandler)
{
	if (inEventHandler) {
		//eventHandler=inEventHandler;
		if (listOfEventHandlers) {
			listOfEventHandlers->push_back(inEventHandler);
		}
	}
}


/**
 *
 */
void EventSystem::removeEventHandler(EventHandlerPtr inEventHandler)
{
	std::list<EventHandlerPtr>::iterator iter;
	EventHandlerPtr currentEventHandler = boost::shared_ptr<EventHandler>();
	
	if (listOfEventHandlers) {
		
		for (iter=listOfEventHandlers->begin();iter!=listOfEventHandlers->end();) {
			currentEventHandler = (*iter);
			
			if (inEventHandler) {
				
			}
			
			++iter;
		}
	}
	
}


/**
 *
 */
void EventSystem::doHandleEvents(ALLEGRO_EVENT ev, EventHandlerPtr eventHandler)
{
	
	switch (ev.type) {
	case ALLEGRO_EVENT_DISPLAY_CLOSE:
		{
			eventHandler->handleQuitEvent();
		}
		break;
		/*
	case ALLEGRO_EVENT_KEY_DOWN:
		{
			printf("ALLEGRO_EVENT_KEY_DOWN\n");
			KeyEvent keyboardEvent(ev);
			eventHandler->handleKeyboard(keyboardEvent);
		}
		break;
		*/
	case ALLEGRO_EVENT_KEY_CHAR:
		{
			//printf("ALLEGRO_EVENT_KEY_CHAR\n");
			KeyEvent keyboardEvent(ev);
			
			eventHandler.get()->handleKeyboard(keyboardEvent);
			
		}
		break;
	case SIMPLE_USER_EVENT_TYPE:
		{
			UserEvent userEvent(ev);
			eventHandler->handleUserEvent(userEvent);
		}
		break;
	case ALLEGRO_EVENT_MOUSE_AXES:
		{
			MouseMotionEvent mouseMotionEvent(ev);
			
			eventHandler->handleMouseMotion(mouseMotionEvent);
		}
		break;
	case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
	case ALLEGRO_EVENT_MOUSE_BUTTON_UP:
		{
			MouseButtonEvent mouseButtonEvent(ev);

			eventHandler->handleMouseButton(mouseButtonEvent);
		}
		break;
	case ALLEGRO_EVENT_MOUSE_ENTER_DISPLAY:
	case ALLEGRO_EVENT_MOUSE_LEAVE_DISPLAY:
		{
			ActiveEvent activeEvent(ev);
			eventHandler->handleActiveEvent(activeEvent);
		}
		break;
	case ALLEGRO_EVENT_DISPLAY_SWITCH_IN:
	case ALLEGRO_EVENT_DISPLAY_SWITCH_OUT:
		{
			ActiveEvent activeEvent(ev);
			eventHandler->handleActiveEvent(activeEvent);
		}
		break;
	}
}


/**
 *
 */
void EventSystem::handleEvents()
{
	ALLEGRO_EVENT ev;
	bool get_event = false;
	
	// Make sure to handle all events in the queue before drawing
	do {
		get_event = al_wait_for_event_until(eventQueue, &ev, &timeout);
		
		if (get_event) {
			EventHandlerPtr currentEventHandler = boost::shared_ptr<EventHandler>();
			
			std::list<EventHandlerPtr>::iterator iter;
			
			for (iter=listOfEventHandlers->begin();iter!=listOfEventHandlers->end();) {
				
				currentEventHandler=(*iter);
				
				if (currentEventHandler) {
					doHandleEvents(ev,currentEventHandler);
				}
				
				++iter;
			}
			
			/*
			if (eventHandler) {
								
				doHandleEvents(ev, eventHandler);
			}
			*/
		}
	}
	while(get_event);
}


/**
 *
 */
ALLEGRO_EVENT_SOURCE *EventSystem::getUserEventSource()
{
	return &userEventSource;
}


// end of namespace
// ----------------
};

// end of namespace
// ----------------
};
