#
#	This file is part of freedungeon
#	Copyright (C) 2013 Andreas Rönnquist
#
#	freedungeon is free software: you can redistribute it and/or 
#	modify it under the terms of the GNU General Public License as published 
#	by the Free Software Foundation, either version 3 of the License, or
#	(at your option) any later version.
#
#	freedungeon is distributed in the hope that it will be useful,
#	but WITHOUT ANY WARRANTY; without even the implied warranty of
#	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#	GNU General Public License for more details.
#
#	You should have received a copy of the GNU General Public License
#	along with freedungeon.  
#	If not, see <http://www.gnu.org/licenses/>.
#

project(gusgame)

cmake_minimum_required(VERSION 3.10.2)

set(LIBRARY_NAME gusgame)


set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/lib)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR})
list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)

# Silence OpenGL cmake policy warnings
# See CMP0072 for more details (cmake --help-policy CMP0072)
if ((NOT ${CMAKE_VERSION} VERSION_LESS 3.11) AND (NOT OpenGL_GL_PREFERENCE))
  set(OpenGL_GL_PREFERENCE "GLVND")
endif()


find_package(OpenGL REQUIRED)
find_package(Allegro5 REQUIRED)

if (DEBUG)
   message(STATUS "Building Debug executable")
   set(CMAKE_BUILD_TYPE "Debug")
   add_definitions(-D_DEBUG)
   #add_definitions(-Wwrite-strings 
         #-Wextra 
         #-Wall 
         #-Winit-self 
         #-O 
         #-Wno-uninitialized 
         #-Wno-unused-parameter 
         #-Wno-switch
         #-w
         #-Wreturn-type
         #-Weffc++
      #)
   # Cpp only flags: (Will not be applied to C files.)
   set(CMAKE_CXX_FLAGS -Weffc++)
   
else (DEBUG)
   message(STATUS "Building Release executable")
   #add_definitions(-fomit-frame-pointer)
   set(CMAKE_BUILD_TYPE "Release")
   
endif (DEBUG)

message(STATUS "Build shared: ${BUILD_SHARED}")

message(STATUS "Allegro 5: ${ALLEGRO_LIBRARIES}")

if (NOT ALLEGRO_FOUND)
   message(FATAL_ERROR "Allegro not found!")
endif (NOT ALLEGRO_FOUND)


add_custom_target(cppcheck
      cppcheck -I/usr/include -I/usr/local/include
   --inline-suppr --enable=all --std=c++20 ../src/

   #cppcheck --suppress=missingIncludeSystem --inline-suppr --enable=all ../src/
   # cppcheck --suppress=missingIncludeSystem --suppress=unmatchedSuppression:src/script.c -i src/icons/icons_resources.c --inline-suppr --enable=all ./src/
)

include_directories(include ${CMAKE_SOURCE_DIR}/include)
include_directories(include ${CMAKE_SOURCE_DIR}/include/GusGame)

include_directories(include ${ALLEGRO_INCLUDE_DIR})

set(INC include/GusGame)

set(INCLUDE_FILES
   ${INC}/System.h
   ${INC}/Library.h
   
   ${INC}/FileHelper.h
   ${INC}/StringHelper.h
   
   ${INC}/LogHandler.h
   ${INC}/Log.h
   ${INC}/LogLib.h
   
   ${INC}/DynamicLink.h

   ${INC}/Error.h
   ${INC}/Exception.h
   ${INC}/FileNotFoundException.h
   ${INC}/RuntimeError.h
   ${INC}/StringToIntException.h
   ${INC}/ExceptionLib.h
   
   ${INC}/GraphicsLib.h
   ${INC}/GraphicsHandler.h
   ${INC}/Color.h
   ${INC}/Bitmap.h
   ${INC}/Timer.h
   ${INC}/Mouse.h
   ${INC}/Primitives.h
   
   ${INC}/EventHandler.h
   ${INC}/ActiveEvent.h
   ${INC}/EventSystem.h
   ${INC}/UserEvent.h
   ${INC}/EventData.h
   ${INC}/KeyEvent.h
   ${INC}/MouseMotionEvent.h
   ${INC}/MouseButtonEvent.h
   ${INC}/MouseScrollerEvent.h
   ${INC}/EventLib.h
   ${INC}/ResizeEvent.h
   
   ${INC}/Rect.h
   ${INC}/Vector2d.h
   
   ${INC}/SystemQuitEvent.h
   ${INC}/QuitEvent.h
   
   ${INC}/Font.h
   ${INC}/FontHandler.h
   ${INC}/BitmapFont.h
   
   ${INC}/GusGame.h
   
   ${INC}/SoundHandler.h
)

set(SOURCES
   src/HelperLib/FileHelper.cpp
   src/HelperLib/StringHelper.cpp
   
   src/LogLib/Log.cpp
   src/LogLib/LogHandler.cpp
   
   src/ExceptionLib/Error.cpp
   src/ExceptionLib/Exception.cpp
   src/ExceptionLib/FileNotFoundException.cpp
   src/ExceptionLib/RuntimeError.cpp
   src/ExceptionLib/StringToIntException.cpp
   
   src/GraphicsLib/GraphicsHandler.cpp
   src/GraphicsLib/Color.cpp
   src/GraphicsLib/Font.cpp
   src/GraphicsLib/BitmapFont.cpp
   src/GraphicsLib/FontHandler.cpp
   src/GraphicsLib/Timer.cpp
   src/GraphicsLib/Bitmap.cpp
   src/GraphicsLib/Mouse.cpp
   src/GraphicsLib/Primitives.cpp
   
   src/System.cpp
   
   src/EventLib/ActiveEvent.cpp
   src/EventLib/UserEvent.cpp
   src/EventLib/EventData.cpp
   src/EventLib/KeyEvent.cpp
   src/EventLib/EventHandler.cpp
   src/EventLib/EventSystem.cpp
   src/EventLib/MouseMotionEvent.cpp
   src/EventLib/MouseButtonEvent.cpp
   src/EventLib/MouseScrollerEvent.cpp
   src/EventLib/SystemQuitEvent.cpp
   src/EventLib/QuitEvent.cpp
   src/EventLib/ResizeEvent.cpp
   
   src/SoundLib/SoundHandler.cpp
)

if (WIN32)
   if (MSYS) 
      Set (WINGL_LIBS glu32 glaux)
   else (MSYS)
      Set (WINGL_LIBS glu32)
   endif (MSYS)

endif(WIN32)

if (USE_GLEW) 
   set (MY_GLEW_LIB ${GLEW_LIBRARY})
else (USE_GLEW)
   set (MY_GLEW_LIB )
endif (USE_GLEW)

if (MSYS)
   set (GL_LIBS ${OPENGL_LIBRARY} ${OPENGL_LIBRARIES})
else (MSYS)
   set (GL_LIBS ${OPENGL_LIBRARY})
endif (MSYS)

set(ALL_LIBS
   ${GL_LIBS}
   ${GLUT_LIBRARY}
   ${ALLEGRO_LIBRARIES}	
)

link_libraries(${ALL_LIBS})

if (${BUILD_SHARED}) 
   set(BUILD_TYPE SHARED)
else (${BUILD_SHARED}) 
   set(BUILD_TYPE STATIC)
endif (${BUILD_SHARED})

add_library(${LIBRARY_NAME} ${BUILD_TYPE} ${SOURCES} ${INCLUDE_FILES})

set(EX_DIR examples)

add_executable(example1 WIN32 ${EX_DIR}/example1.cpp)
target_link_libraries(example1 ${ALL_LIBS} ${LIBRARY_NAME})

add_executable(example2 WIN32 ${EX_DIR}/example2.cpp)
target_link_libraries(example2 ${ALL_LIBS} ${LIBRARY_NAME})

add_executable(example3 WIN32 ${EX_DIR}/example3.cpp)
target_link_libraries(example3 ${ALL_LIBS} ${LIBRARY_NAME})

add_executable(example4 WIN32 ${EX_DIR}/example4.cpp)
target_link_libraries(example4 ${ALL_LIBS} ${LIBRARY_NAME})

add_executable(example5 WIN32 ${EX_DIR}/example5.cpp)
target_link_libraries(example5 ${ALL_LIBS} ${LIBRARY_NAME})

add_executable(example6 WIN32 ${EX_DIR}/example6.cpp)
target_link_libraries(example6 ${ALL_LIBS} ${LIBRARY_NAME})

add_executable(example7 WIN32 ${EX_DIR}/example7.cpp)
target_link_libraries(example7 ${ALL_LIBS} ${LIBRARY_NAME})

add_executable(example8 WIN32 ${EX_DIR}/example8.cpp)
target_link_libraries(example8 ${ALL_LIBS} ${LIBRARY_NAME})

add_executable(example9 WIN32 ${EX_DIR}/example9.cpp)
target_link_libraries(example9 ${ALL_LIBS} ${LIBRARY_NAME})

add_executable(example10 WIN32 ${EX_DIR}/example10.cpp)
target_link_libraries(example10 ${ALL_LIBS} ${LIBRARY_NAME})

install_targets(/lib ${LIBRARY_NAME})

install(FILES ${INCLUDE_FILES} DESTINATION include/GusGame)
