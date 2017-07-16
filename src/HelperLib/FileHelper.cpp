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
#include <boost/filesystem.hpp>
#include <sys/stat.h>

#include <string>
#include <list>
#include <sstream>

#include <sys/types.h>

#if STAT_MACROS_BROKEN
# undef S_ISDIR
#endif

#if !defined S_ISDIR && defined S_IFDIR
# define S_ISDIR(Mode) (((Mode) & S_IFMT) == S_IFDIR)
#endif

#include "FileHelper.h"

#include "Log.h"
#include "LogHandler.h"

/**
 *
 */
namespace Gus
{

std::list<std::string> FileHelper::m_DataFolders;


/**
 *
 */
void FileHelper::addDataFolder(std::string folder)
{
	m_DataFolders.push_back(folder);
}


/**
 *
 */
bool FileHelper::isDir(std::string in_string)
{
	struct stat stats;

	if (((stat((char*)(in_string.c_str()), &stats) == 0) && (S_ISDIR(stats.st_mode)) != 0)) return true;

	return false;
}


/**
 *
 */
bool FileHelper::fileExists(std::string strFilename)
{
	FILE* fp = NULL;

	/*
	std::stringstream st;
	st << "fileExists(" << strFilename << ")";
	STLOG(st);
	*/

	bool result = false;
#ifdef _MSC_VER
	fopen_s(&fp, (char*)(strFilename.c_str()), "r" );
#else
	fp = fopen( (char*)(strFilename.c_str()), "r" );
#endif
	if( fp != NULL )
	{
		fclose( fp );

		result=true;
		if (isDir(strFilename)) result = false;

	}

	return result;
}


/**
 *	fixBeginSlashFilename
 *	Fixes the filename so that it doesn't begin with a slash (should not be
 * called on absolute path's then, obviously, only on relative paths)
 */
std::string FileHelper::fixBeginSlashFilename(std::string inFilename)
{
	std::string result = inFilename;

	// Fix so that the string doesn't start with a
	if (result[0] == '/') {
		result = inFilename.substr(1);
	}

	return result;
}

/**
 *	returns a complete filename, with a filename in the style of
 * mouse.png as indata. This it does by trying by using the folders
 * in the m_DataFolders list of folders.
 */
std::string FileHelper::getFilename(std::string inFilename)
{
	std::string result = "";

#ifdef _WIN32
	if ((inFilename[1] == ':') &&
		((inFilename[2] == '/') || (inFilename[2] == '\\'))) {
#else
	if (inFilename[0] == '/') {
#endif
		return inFilename;
	}

	std::list<std::string>::iterator iter;
	for (iter = m_DataFolders.begin(); iter != m_DataFolders.end(); ) {

		std::string temp = *iter;
		std::string testResult = temp; //fixFilename(temp);
		int len = testResult.length();

		// if we have a proper length:
		if (len > 0) {
			// make sure the string ends with a slash
			if (testResult[len - 1] != '/') {
				testResult += "/";
			}
		}

		testResult += fixBeginSlashFilename(inFilename);

		//testResult=fixFilename(testResult);


		/*
		std::stringstream logst;
		logst << "Testing:" << testResult;
		STLOG(logst);
		*/


		if (FileHelper::fileExists(testResult)) {
			//LOG("File Exists TRUE");
			if (result == "") result = testResult;
		} else {
			//LOG("File Exists FALSE");
		}

		if (result != "") {
			/*
			std::stringstream logst;
			logst << "FOUND:" << result;
			STLOG(logst);
			*/
			iter = m_DataFolders.end();
			//leaveLoop=true;
			break;
			//++iter;
		} else {

			++iter;
		}
	}

	return result;
}


/**
 *
 */
bool FileHelper::isSlash(char ch)
{
	if ((ch == '/') || (ch == '\\')) {
		return true;
	}

	return false;
}


/**
 *
 */
std::string FileHelper::fixEndSlash(const std::string &text)
{
	std::string result = text;

	if (text.length() == 0) {
		result += SLASH;
		return result;
	}

	if (!isSlash(text[text.length() - 1])) {
		result += SLASH;
	}

	return result;
}


/**
 *
 */
std::string FileHelper::fixSlashes(const std::string &text)
{
	std::string result=text;

	for (unsigned int co = 0; co < (unsigned int)text.length(); co++) {
		if (isSlash(text[co])) {
			result[co] = SLASH;
		}
	}
	return result;
}


/**
 *
 */
std::string FileHelper::getAbsolutePath(const std::string &inString)
{
	LOG("Hej!");
	// boost::filesystem::path canonicalPath = boost::filesystem::canonical(previousPath, relativeTo);
	
	boost::filesystem::path inPath = boost::filesystem::path(inString);
	
	
	boost::filesystem::path canonicalPath = boost::filesystem::weakly_canonical(inPath);
	LOG("Nej!");
	return canonicalPath.string();
}

// end of namespace
// ----------------
};
