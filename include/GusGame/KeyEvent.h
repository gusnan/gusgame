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
#ifndef __HEADER_KEY_EVENT_
#define __HEADER_KEY_EVENT_

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
enum KeyEventType{KeyEventPressed, KeyEventReleased};


namespace Key
{
enum KeyNames
{
	Space=	' ',
	Tab=		'\t',
	Enter=		'\n',
	LeftAlt=		1000,
	RightAlt,
	RightShift,
	LeftShift,
	RightControl,
	LeftControl,
	RightMeta,
	LeftMeta,
	RightSuper,LeftSuper,
	Insert,
	Home,
	PageUp,
	PageDown,
	Delete,
	End,
	Escape,
	CapsLock,
	Backspace,
	F1,F2,F3,F4,F5,F6,F7,F8,F9,F10,F11,F12,F13,F14,F15,
	PrintScreen,
	ScrollLock,
	Pause,
	NumLock,
	AltGr,
	Left,Right,Up,Down,
	A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z,
	KeyPad0,KeyPad1,KeyPad2,KeyPad3,KeyPad4,
	KeyPad5,KeyPad6,KeyPad7,KeyPad8,KeyPad9,
	Key1,Key2,Key3,Key4,Key5,Key6,Key7,Key8,Key9,Key0,
	Minus, Plus, Equals
};

};



/**
 *
 */
class KeyEvent
{
public:
	KeyEvent();
	KeyEvent(const KeyEvent &source);
	KeyEvent &operator=(const KeyEvent &source);

	KeyEvent(ALLEGRO_EVENT event);

	virtual ~KeyEvent();

	KeyEventType getType() const;

	void setValue(int value);
	int getValue() const;

	bool getShiftPressed() const;
	void setShiftPressed(bool pressed);

	bool getAltPressed() const;
	void setAltPressed(bool pressed);

	bool getCtrlPressed() const;
	void setCtrlPressed(bool pressed);

	bool getMetaPressed() const;
	void setMetaPressed(bool pressed);


protected:
	KeyEventType m_KeyEventType;
	int m_Value;

	int convertAllegroToKeyValue(int alValue);

	bool m_AltPressed;
	bool m_CtrlPressed;
	bool m_ShiftPressed;
	bool m_MetaPressed;

};

// end of namespace
// ----------------
};

// end of namespace
// ----------------
};

#endif /*__HEADER_KEY_EVENT_*/
