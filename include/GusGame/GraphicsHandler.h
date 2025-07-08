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
#ifndef __HEADER_GRAPHICS_HANDLER_
#define __HEADER_GRAPHICS_HANDLER_

#include "Bitmap.h"

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

const int SET_GRAPHICS_RESULT_OK =           0;
const int SET_GRAPHICS_RESULT_NO_OPEN_GL =   1;


/**
 *
 */
class GraphicsHandler
{
public:

   static GraphicsHandler &instance();

   float getZoomX();
   float getZoomY();

   ALLEGRO_DISPLAY *getDisplay();

   void initGraphicsHandler();
   void doneGraphicsHandler();

   int setGraphicsMode(const Vector2d &windowSize, const Vector2d &graphicsSize, bool fullscreen, bool resizable);
   int setGraphicsMode(const Vector2d &size, bool fullscreen, bool resizable = false);
   void setBackgroundSize(const Vector2d &size);

   void setWindowTitle(const std::string &title);

   void clearScreen();
   void updateScreen();

   Rect getScreenRect();

   void setClipRect(const Rect &rect);
   void noClip();

   std::string getOpenGLVersionString();

   void setIcon(std::shared_ptr<Gus::GraphicsLib::Bitmap> icon);

   Vector2d getDisplayResolution();

protected:

   GraphicsHandler();

   virtual ~GraphicsHandler();

private:
   GraphicsHandler(const GraphicsHandler &inGraphicsHandler);
   GraphicsHandler &operator=(const GraphicsHandler &inGraphicsHandler);

   Vector2d screenSize;
   Vector2d backgroundSize;

   float zoomX, zoomY;

   ALLEGRO_DISPLAY *display;
};

// end of namespace
// ----------------
};

// end of namespace
// ----------------
};


#endif
