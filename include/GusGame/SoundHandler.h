/**
 *
 *	This file is part of GusGame
 *	Copyright (C) 2025 Andreas Rönnquist
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
#ifndef __HEADER_SOUND_HANDLER_
#define __HEADER_SOUND_HANDLER_
/**
 *
 */
namespace Gus
{

/**
 *
 */
namespace SoundLib
{


/**
 *
 */
class SoundHandler
{
public:

   static SoundHandler &instance();


protected:

   SoundHandler();

   virtual ~SoundHandler();

private:
   SoundHandler(const SoundHandler &inSoundHandler);
   SoundHandler &operator=(const SoundHandler &inSoundHandler);

};

// enf of namesapce SoundLib
};

// enf of namesapce Gus
};

#endif /*__HEADER_SOUND_HANDLER_*/
