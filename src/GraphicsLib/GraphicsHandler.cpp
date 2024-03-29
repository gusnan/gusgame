/**
 *
 *	This file is part of GusGame
 *	Copyright (C) 2013-2017 Andreas Rönnquist
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
#include <stdint.h>
#include <sstream>
#include <memory>

#include "Library.h"

#include "Vector2d.h"
#include "Rect.h"

#include "Exception.h"

#include "Color.h"

#include "Bitmap.h"

#include "GraphicsHandler.h"

#include "Timer.h"

/**
 *
 */
namespace Gus
{


/**
 *
 */
namespace GraphicsLib
{

/**
 *
 */
GraphicsHandler &GraphicsHandler::instance()
{
   static GraphicsHandler instance;

   return instance;
}


/**
 *
 */
GraphicsHandler::GraphicsHandler(const GraphicsHandler &inGraphicsHandler) : screenSize(),
                                                                             backgroundSize(),
                                                                             zoomX(),
                                                                             zoomY(),
                                                                             display(nullptr)
{
}


/**
 *
 */
GraphicsHandler::~GraphicsHandler()
{
   doneGraphicsHandler();
}


/**
 *
 */
GraphicsHandler &GraphicsHandler::operator=(const GraphicsHandler &inGraphicsHandler)
{
   screenSize = inGraphicsHandler.screenSize;
   backgroundSize = inGraphicsHandler.backgroundSize;
   zoomX = inGraphicsHandler.zoomX;
   zoomY = inGraphicsHandler.zoomY;
   display = inGraphicsHandler.display;


   return *this;
}


/**
 *
 */
GraphicsHandler::GraphicsHandler() : screenSize(),
                                     backgroundSize(),
                                     zoomX(),
                                     zoomY(),
                                     display(nullptr)
{
}


/**
 *
 */
void GraphicsHandler::initGraphicsHandler()
{
   Timer::initTimer();
}


/**
 *
 */
void GraphicsHandler::doneGraphicsHandler()
{

   if (display != nullptr) {
      al_destroy_display(display);
      display = nullptr;
   }

   Timer::doneTimer();

}


/**
 *
 */
std::string GraphicsHandler::getOpenGLVersionString()
{
   uint32_t openGLversion = al_get_opengl_version();

   /*
   std::cout << ((openGLversion >> 24) % 0x100) << std::endl;
   std::cout << ((openGLversion >> 16) % 0x100) << std::endl;
   std::cout << ((openGLversion >> 8) % 0x100) << std::endl;
   std::cout << (openGLversion % 0x100) << std::endl;
   */

   std::stringstream result;

   //result << openGLversion;

   result << ((openGLversion >> 24) % 0x100) << "." <<
             ((openGLversion >> 16) % 0x100) << "." <<
             ((openGLversion >> 8) % 0x100) << "."<< (openGLversion % 0x100);

   return (std::string)(result.str());
}


/**
 *
 */
int GraphicsHandler::setGraphicsMode(const Vector2d &size, bool fullscreen, bool resizable)
{
   int set_graphics_result = SET_GRAPHICS_RESULT_OK;
   int flags = 0;

   if (fullscreen) {
      flags |= ALLEGRO_FULLSCREEN;
   } else {
      flags |= ALLEGRO_WINDOWED;
   }

   flags |= ALLEGRO_OPENGL;

   if (resizable) flags |= ALLEGRO_RESIZABLE;

   al_set_new_display_flags(flags);

   display = al_create_display(size.x, size.y);

   // Couldn't set the display when using ALLEGRO_OPENGL flag,
   // now try without (This happens with Windows under VirtualBox)
   if (!display) {
      flags ^= ALLEGRO_OPENGL;

      al_set_new_display_flags(flags);

      display = al_create_display(size.x, size.y);

      set_graphics_result = SET_GRAPHICS_RESULT_NO_OPEN_GL;
   }

   screenSize = size;
   setBackgroundSize(screenSize);

   if (!display) {
      throw ExceptionLib::Exception("Couldn't init display!");
   }

   //al_set_window_position(display, 32, 32);
   return set_graphics_result;
}


/**
 *
 */
void GraphicsHandler::setBackgroundSize(const Vector2d &size)
{
   backgroundSize = size;
   
   zoomX = (float)screenSize.x / (float)backgroundSize.x;
   zoomY = (float)screenSize.y / (float)backgroundSize.y;
}


/**
 *
 */
void GraphicsHandler::setWindowTitle(const std::string &windowTitle)
{
   if (display)
      al_set_window_title(display, const_cast<const char*>(windowTitle.c_str()));
}


/**
 *
 */
void GraphicsHandler::clearScreen()
{
   al_clear_to_color(al_map_rgb(0, 0, 0));
}


/**
 *
 */
void GraphicsHandler::updateScreen()
{
   Timer::timerValue1 = Timer::timerValue2;
   Timer::timerValue2 = al_get_time();

   al_flip_display();
}


/**
 *
 */
Rect GraphicsHandler::getScreenRect()
{
   return Rect(Vector2d(0, 0), backgroundSize);
}


/**
 *
 */
void GraphicsHandler::setClipRect(const Rect &rect)
{
   int x = (float)rect.position.x * (float)GraphicsHandler::zoomX;
   int y = (float)rect.position.y * (float)GraphicsHandler::zoomY;

   int xs = (float)rect.size.x * (float)GraphicsHandler::zoomX;
   int ys = (float)rect.size.y * (float)GraphicsHandler::zoomY;

   al_set_clipping_rectangle(x, y, xs, ys);
}


/**
 *
 */
void GraphicsHandler::noClip()
{
   setClipRect(getScreenRect());
}


/**
 *
 */
void GraphicsHandler::setIcon(std::shared_ptr<Bitmap> icon)
{
   if (display) {
      if (icon) {
         al_set_display_icon(display, icon->getAllegroBitmap());
      }
   }
}


/**
 *
 */
Vector2d GraphicsHandler::getDisplayResolution()
{
   int w = 0, h = 0;

   if (display != nullptr) {
      w = al_get_display_width(display);
      h = al_get_display_height(display);
   }

   return Vector2d(w, h);
}

/**
 *
 */
float GraphicsHandler::getZoomX()
{
   return zoomX;
}

/**
 *
 */
float GraphicsHandler::getZoomY()
{
   return zoomY;
}

/**
 *
 */
ALLEGRO_DISPLAY *GraphicsHandler::getDisplay()
{
   return display;
}



// end of namespace
// ----------------
};

// end of namespace
// ----------------
};
