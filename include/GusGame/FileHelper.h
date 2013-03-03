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
#ifndef __HEADER_FILEHELPER_
#define __HEADER_FILEHELPER_


#ifdef _WIN32
#define SLASH '\\'
#else
#define SLASH '/'
#endif

/**
 *
 */
namespace Gus
{
	
/**
 *
 */
namespace FileHelper
{

	bool isSlash(char ch);
	
	bool isDir(std::string in_string);
	
	bool fileExists(std::string strFilename);
	std::string fixBeginSlashFilename(std::string inFilename);
	
	std::string fixEndSlash(const std::string &text);
	
	void addDataFolder(std::string);
	std::string getFilename(std::string);

	std::string fixSlashes(const std::string &text);
	
	extern std::list<std::string> m_DataFolders;
	
};

	
// end of namespace
// ----------------
};

#endif /*__HEADER_FILEHELPER_*/
