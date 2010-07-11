
/*
 *
 * baselevel.h
 *
 * 30th March 2010: Created baselevel.h from parts of level.h
 *
 * Part of the OpenJazz project
 *
 *
 * Copyright (c) 2005-2010 Alister Thomson
 *
 * OpenJazz is distributed under the terms of
 * the GNU General Public License, version 2.0
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */


#ifndef _BASELEVEL_H
#define _BASELEVEL_H


#include "io/gfx/paletteeffects.h"
#include "menu/menu.h"


// Macros

// For converting between tile positions and int/fixed values
#define FTOT(x) ((x) >> 15)
#define TTOF(x) ((x) << 15)
#define ITOT(x) ((x) >> 5)
#define TTOI(x) ((x) << 5)


// Enums

enum LevelType {

	LT_LEVEL, LT_BONUS, LT_JJ2LEVEL

};

enum LevelStats {

	S_PLAYERS = 1, S_SCREEN = 2

};

enum LevelStage {

	LS_NORMAL = 0, LS_SUDDENDEATH = 1, LS_END = 2

};


// Classes

class File;
class Sprite;

class BaseLevel {

	private:
		SetupMenu setupMenu;

	protected:
		PaletteEffect* paletteEffects;
		SDL_Color      palette[256];
		int            sprites;
		unsigned int   tickOffset, prevStepTicks, prevTicks, ticks;
		unsigned int   endTime;
		float          smoothfps;
		int            items;
		bool           multiplayer;
		bool           paused;
		LevelStage     stage;
		int            stats;

		int  playScene (char* file);
		void timeCalcs ();
		void drawStats (unsigned char bg);
		int  loop      (bool& menu, int& option, bool& message);

	public:
		BaseLevel          ();
		virtual ~BaseLevel ();

		void         addTimer ();
		LevelStage   getStage ();
		void         setStage (LevelStage stage);
		virtual void receive  (unsigned char* buffer) = 0;

};


// Variables

EXTERN BaseLevel* baseLevel;
EXTERN fixed  viewX, viewY;

#endif

