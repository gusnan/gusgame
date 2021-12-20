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
#include <iostream>

#include <fstream>

#include <sstream>
#include <exception>

#include "ExceptionLib.h"
using namespace Gus::ExceptionLib;

#include <time.h>

#include "Log.h"

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

#define COLON ": "
   
   
/**
 *
 */
GUSGAME_DLL Log::Log(std::string filename,bool activeFileLog,bool activeScreenLog) : m_Indent(0), m_FileLogActive(activeFileLog), m_ScreenLogActive(activeScreenLog), m_File(), m_Filename(filename)
{
   if (m_FileLogActive) {
      m_File.open((char*)(m_Filename.c_str()), std::fstream::trunc);
      
      m_File << std::endl;
      m_File << getTime() << COLON;
      m_File << "Initing log..." << std::endl;
      m_File << getTime() << COLON;
      m_File << "Current Date is:" << getDate() << std::endl;
   }
      
   if (m_ScreenLogActive) {
      std::cout << std::endl;
      std::cout << getTime() << COLON;
      std::cout << "Initing log..." << std::endl;
      std::cout << getTime() << COLON;
      std::cout << "Current Date is:" << getDate() << std::endl;
   }
   
   addLine();
   closeFile();
}


/**
 *
 */
GUSGAME_DLL Log::~Log()
{
   closeFile();
   addLine();

   openFile();
   if (m_FileLogActive) {
      m_File << getTime() << COLON;
      m_File << "Done log..." << std::endl;
      if (m_File.is_open()) {
         m_File.close();
      }
   }
   
   closeFile();
      
   if (m_ScreenLogActive) {
      std::cout << getTime() << COLON;
      std::cout << "Done log..." << std::endl;
   }

}


/**
 *
 */
void GUSGAME_DLL Log::add(std::string message)
{
   openFile();
   if (m_FileLogActive) {
      m_File << getTime() << COLON;
      for (int co = 0; co < m_Indent; co++) {
         m_File << "   ";
      }
      m_File << message << std::endl;
      m_File.flush();
   }
   closeFile();
   
   if (m_ScreenLogActive) {
      std::cout << getTime() << COLON;
      for (int co = 0; co < m_Indent; co++) {
         std::cout << "   ";
      }
      std::cout << message << std::endl;
   }

}


/**
 *
 */
void GUSGAME_DLL Log::add(std::stringstream message)
{
   openFile();
   if (m_FileLogActive) {
      m_File << getTime() << COLON;
      for (int co = 0; co < m_Indent; co++) {
         m_File << "   ";
      }
      m_File << message.str();
      m_File.flush();
   }
   
   if (m_ScreenLogActive) {
      std::cout << getTime() << COLON;
      for (int co = 0; co < m_Indent; co++) {
         std::cout << "   ";
      }
      std::cout << message.str() << std::endl;
   }
   closeFile();
}


/**
 *
 */
void GUSGAME_DLL Log::addLine()
{
   openFile();
   if (m_FileLogActive) {
      m_File << getTime() << COLON;
      m_File << "-------------------------" << std::endl;
      m_File.flush();
   }
   
   if (m_ScreenLogActive) {
      std::cout << getTime() << COLON;
      std::cout << "------------------------" << std::endl;
   }
   
   closeFile();
}


/**
 *
 */
void GUSGAME_DLL Log::addIndent()
{
   m_Indent++;
}


/**
 *
 */
void GUSGAME_DLL Log::removeIndent()
{
   m_Indent--;
}


/**
 *
 */
std::string GUSGAME_DLL Log::getTime()
{
   time_t rawtime;
   char buffer[80];

   time(&rawtime);

#ifdef _MSC_VER
   struct tm timeinfo;
   localtime_s(&timeinfo,&rawtime);
   strftime(buffer, 80, "%X", &timeinfo);
#else
   struct tm *timeinfo;
   timeinfo = localtime(&rawtime);
   strftime(buffer, 80, "%X", timeinfo);
#endif
   
   return buffer;
}


/**
 *
 */
std::string GUSGAME_DLL Log::getDate()
{
   time_t rawtime;
   char buffer[80];

   time(&rawtime);

#ifdef _MSC_VER
   struct tm timeinfo;
   localtime_s(&timeinfo, &rawtime);
   strftime(buffer, 80, "%x", &timeinfo);
#else
   struct tm *timeinfo;
   timeinfo = localtime(&rawtime);
   strftime(buffer, 80, "%x", timeinfo);
#endif
   
   return buffer;
}


/**
 *
 */
void GUSGAME_DLL Log::openFile()
{
   /*if (m_LogActive) {
      m_File.open((char*)(m_Filename.c_str()), std::fstream::ate);
   }
   */
   
}


/**
 *
 */
void GUSGAME_DLL Log::closeFile()
{
   /*if (m_LogActive) {
      m_File.flush();
      m_File.close();
   }*/
}


// end of namespace
// ----------------
};

// end of namespace
// ----------------
};
