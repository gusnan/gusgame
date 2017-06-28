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
#include "MouseScrollerEvent.h"

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
ALLEGRO_EVENT_QUEUE *EventSystem::eventQueue = NULL;
//EventHandler *EventSystem::eventHandler=NULL;
ALLEGRO_TIMEOUT timeout;

ALLEGRO_EVENT_SOURCE EventSystem::userEventSource;

std::list<EventHandlerPtr> *EventSystem::listOfEventHandlers = NULL;

std::list<UserEvent*> *EventSystem::listDelayedEvents = NULL;


std::list<EventHandlerPtr> *EventSystem::handlersToRemove = NULL;

// Check if we are in a event loop, and don't remove event from the list
// in that case, but instead do it after the loop.
bool EventSystem::inEventLoop = false;

/**
 *
 */
void EventSystem::initEventSystem()
{
	LOG("initEventSystem");

	eventQueue = al_create_event_queue();
	if (!eventQueue) {
		throw ExceptionLib::Exception("Could crate event queue!");
	}

	al_init_user_event_source(&userEventSource);

	listOfEventHandlers = new std::list<EventHandlerPtr>;

	listOfEventHandlers->clear();

	al_register_event_source(eventQueue, &userEventSource);

	ALLEGRO_EVENT_SOURCE *display_event_source = al_get_display_event_source(GraphicsLib::GraphicsHandler::display);
	if (display_event_source) {
		al_register_event_source(eventQueue, display_event_source);
	}

	ALLEGRO_EVENT_SOURCE *keyboard_event_source = al_get_keyboard_event_source();
	if (keyboard_event_source) {
		al_register_event_source(eventQueue, keyboard_event_source);
	}

	al_register_event_source(eventQueue, al_get_mouse_event_source());

	al_init_timeout(&timeout, 0.1);

	listDelayedEvents = new std::list<UserEvent*>();
	listDelayedEvents->clear();

	handlersToRemove = new std::list<EventHandlerPtr>();
	handlersToRemove->clear();

	inEventLoop = false;
}


/**
 *
 */
void EventSystem::doneEventSystem()
{
	//std::list<EventHandler*>::iterator iter;

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
		listOfEventHandlers = 0;
	}

	if (listDelayedEvents) {
		delete listDelayedEvents;
		listDelayedEvents = 0;
	}

	if (handlersToRemove) {
		delete handlersToRemove;
		handlersToRemove = 0;
	}
}


/**
 *
 */
void EventSystem::addEventHandler(EventHandlerPtr inEventHandler)
{

	if (inEventHandler != boost::shared_ptr<EventHandler>()) {
		//eventHandler=inEventHandler;
		if (listOfEventHandlers) {
			listOfEventHandlers->push_back(inEventHandler);

			/*
			std::stringstream st;

			st << "Adding:" << inEventHandler.get()->getName();
			STLOG(st);
			*/
		}
	}
}


/**
 *
 */
void EventSystem::removeEventHandler(EventHandlerPtr inEventHandler)
{
	std::list<EventHandlerPtr>::iterator iter;
	EventHandlerPtr currentEventHandler;  // = boost::shared_ptr<EventHandler>();

	EventHandlerPtr inEvent = inEventHandler/*.get()*/;

	if (inEventLoop) {
		if (handlersToRemove) {
			handlersToRemove->push_back(inEventHandler);
		}

	} else {

		if (listOfEventHandlers) {

			//listOfEventHandlers->remove_if(ptr_contains(inEventHandler.get()));
			if (!listOfEventHandlers->empty()) {

				for (iter=listOfEventHandlers->begin(); iter != listOfEventHandlers->end();) {
					currentEventHandler = (*iter);

					if (inEvent == currentEventHandler/*.get()*/) {
						LOG("Removed one eventhandler!");

						iter = listOfEventHandlers->erase(iter);

					} else {

						++iter;
					}

				}
			}
		}
	}
}


/**
 * returns true if the event is handled
 */
bool EventSystem::doHandleEvents(ALLEGRO_EVENT ev, EventHandlerPtr eventHandler)
{
	bool result = false;

	switch (ev.type) {
	case ALLEGRO_EVENT_DISPLAY_CLOSE:
		{
			eventHandler.get()->handleQuitEvent();
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

			result = eventHandler.get()->handleKeyboard(keyboardEvent);

		}
		break;
	case SIMPLE_USER_EVENT_TYPE:
		{
			UserEvent userEvent(ev);
			result = eventHandler.get()->handleUserEvent(userEvent);
		}
		break;
	case ALLEGRO_EVENT_MOUSE_AXES:
		{
			if ((ev.mouse.dx != 0) || (ev.mouse.dy != 0)) {
				MouseMotionEvent mouseMotionEvent(ev);

				eventHandler.get()->handleMouseMotion(mouseMotionEvent);
			}

			if (ev.mouse.dz != 0) {

				MouseScrollerEvent mouseScrollerEvent(ev);

				eventHandler.get()->handleMouseScroller(mouseScrollerEvent);
			}
		}
		break;
	case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
	case ALLEGRO_EVENT_MOUSE_BUTTON_UP:
		{
			MouseButtonEvent mouseButtonEvent(ev);

			eventHandler.get()->handleMouseButton(mouseButtonEvent);
		}
		break;
	case ALLEGRO_EVENT_MOUSE_ENTER_DISPLAY:
	case ALLEGRO_EVENT_MOUSE_LEAVE_DISPLAY:
		{
			ActiveEvent activeEvent(ev);
			eventHandler.get()->handleActiveEvent(activeEvent);
		}
		break;
	case ALLEGRO_EVENT_DISPLAY_SWITCH_IN:
	case ALLEGRO_EVENT_DISPLAY_SWITCH_OUT:
		{
			ActiveEvent activeEvent(ev);
			eventHandler.get()->handleActiveEvent(activeEvent);
		}
		break;
	}

	return result;
}


/**
 *
 */
void EventSystem::handleEvents()
{
	ALLEGRO_EVENT ev;
	bool get_event = false;
	boost::shared_ptr<EventHandler> currentEventHandler = boost::shared_ptr<EventHandler>();

	bool eventHandled = false;

	// Make sure to handle all events in the queue before drawing
	inEventLoop = true;
	do {
		if (!al_is_event_queue_empty(eventQueue)) {

			get_event = al_wait_for_event_until(eventQueue, &ev, &timeout);

			if (get_event) {
				if (listOfEventHandlers) {

					if (!listOfEventHandlers->empty()) {

						std::list<boost::shared_ptr<EventHandler> >::iterator iter;

						for (iter = listOfEventHandlers->begin(); iter != listOfEventHandlers->end();) {

							currentEventHandler = (*iter);

							if (currentEventHandler != boost::shared_ptr<EventHandler>()) {

								if (!eventHandled) {
									eventHandled = doHandleEvents(ev, currentEventHandler);
								}
							}
							++iter;
						}
					}
				}

				eventHandled = false;
			}
		} else{
			get_event = false;
		}
	}
	while(get_event);
	inEventLoop = false;


	// Remove the eventhandler items that were queued for removal in the list
	// through eventhandlers above
	if (handlersToRemove) {
		std::list<EventHandlerPtr>::iterator iter;

		if (!handlersToRemove->empty()) {
			for (iter = handlersToRemove->begin(); iter != handlersToRemove->end(); ) {

				removeEventHandler(*iter);
				iter = handlersToRemove->erase(iter);
				// ++iter;
			}
		}
	}

	// Push the delayed events

	std::list<UserEvent*>::iterator iter;

	for (iter = listDelayedEvents->begin(); iter != listDelayedEvents->end(); ++iter) {

		UserEvent *current_event = (*iter);

		ALLEGRO_EVENT userEvent;

		userEvent.user.type = SIMPLE_USER_EVENT_TYPE;
		userEvent.user.data1 = current_event->getUserEventNumber();

		if (!al_emit_user_event(&EventSystem::userEventSource, &userEvent, NULL)) {
			std::cout << "al_emit_user_event FAILED!" << std::endl;
		}
	}

	listDelayedEvents->clear();

}


/**
 *
 */
void EventSystem::printEventHandlers()
{
	// extern std::list<EventHandlerPtr> *listOfEventHandlers;
	std::list<EventHandlerPtr>::iterator iter;


	LOG("List of event handlers:");
	LOG("-----------------------");

	if (listOfEventHandlers) {

		for (iter = listOfEventHandlers->begin(); iter != listOfEventHandlers->end();) {
			EventHandlerPtr handler = (*iter);

			std::stringstream st;

			st << "  " << handler.get()->getName();

			STLOG(st);

			++iter;
		}
	}


	LOG("--------");
}


// end of namespace
// ----------------
};

// end of namespace
// ----------------
};
