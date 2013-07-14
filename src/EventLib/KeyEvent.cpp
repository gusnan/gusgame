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
#include "Library.h"

#include "KeyEvent.h"

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
KeyEvent::KeyEvent() : m_KeyEventType(KeyEventPressed), m_Value(0), 
	m_AltPressed(false), m_CtrlPressed(false), m_ShiftPressed(false), 
	m_MetaPressed(false)
{
}


/**
 *
 */
KeyEvent::KeyEvent(ALLEGRO_EVENT event) : m_KeyEventType(KeyEventPressed), 
	m_Value(0), m_AltPressed(false), m_CtrlPressed(false), 
	m_ShiftPressed(false), m_MetaPressed(false)
{
	//ALLEGRO_EVENT_KEY_CHAR keyEvent=event.keyboard;
	// int keycode=event.keyboard.keycode;
	setValue(convertAllegroToKeyValue(event.keyboard.keycode));
	
	unsigned alModifiers=event.keyboard.modifiers;
	
	setShiftPressed(false);
	if (alModifiers & ALLEGRO_KEYMOD_SHIFT) {
		setShiftPressed(true);
	}
	
	setCtrlPressed(false);
	if (alModifiers & ALLEGRO_KEYMOD_CTRL) {
		setCtrlPressed(true);
	}
	
	setAltPressed(false);
	if (alModifiers & ALLEGRO_KEYMOD_ALT) {
		setAltPressed(true);
	}
	
	m_KeyEventType=KeyEventPressed;
}


/**
 *
 */
KeyEvent::KeyEvent(const KeyEvent &source) : m_KeyEventType(KeyEventPressed), m_Value(0), m_AltPressed(false), 
	m_CtrlPressed(false), m_ShiftPressed(false), m_MetaPressed(false)
{
}


/**
 *
 */
KeyEvent &KeyEvent::operator=(const KeyEvent &source)
{
	if (this != &source) {
	}

	return *this;
}


/**
 *
 */
KeyEvent::~KeyEvent()
{
}


/**
 *
 */
KeyEventType KeyEvent::getType() const
{
	return m_KeyEventType;
}


/**
 *
 */
void KeyEvent::setValue(int value)
{
	m_Value=value;
}


/**
 *
 */
int KeyEvent::getValue() const
{
	return m_Value;
}

/**
 *
 */
int KeyEvent::convertAllegroToKeyValue(int alValue)
{
	int result=-1;
	switch (alValue)
	{
	case ALLEGRO_KEY_A:
		result=Key::A;
		break;
	case ALLEGRO_KEY_B:
		result=Key::B;
		break;
	case ALLEGRO_KEY_C:
		result=Key::C;
		break;
	case ALLEGRO_KEY_D:
		result=Key::D;
		break;
	case ALLEGRO_KEY_E:
		result=Key::E;
		break;
	case ALLEGRO_KEY_F:
		result=Key::F;
		break;
	case ALLEGRO_KEY_G:
		result=Key::G;
		break;
	case ALLEGRO_KEY_H:
		result=Key::H;
		break;
	case ALLEGRO_KEY_I:
		result=Key::I;
		break;
	case ALLEGRO_KEY_J:
		result=Key::J;
		break;
	case ALLEGRO_KEY_K:
		result=Key::K;
		break;
	case ALLEGRO_KEY_L:
		result=Key::L;
		break;
	case ALLEGRO_KEY_M:
		result=Key::M;
		break;
	case ALLEGRO_KEY_N:
		result=Key::N;
		break;
	case ALLEGRO_KEY_O:
		result=Key::O;
		break;
	case ALLEGRO_KEY_P:
		result=Key::P;
		break;
	case ALLEGRO_KEY_Q:
		result=Key::Q;
		break;
	case ALLEGRO_KEY_R:
		result=Key::R;
		break;
	case ALLEGRO_KEY_S:
		result=Key::S;
		break;
	case ALLEGRO_KEY_T:
		result=Key::T;
		break;
	case ALLEGRO_KEY_U:
		result=Key::U;
		break;
	case ALLEGRO_KEY_V:
		result=Key::V;
		break;
	case ALLEGRO_KEY_W:
		result=Key::W;
		break;
	case ALLEGRO_KEY_X:
		result=Key::X;
		break;
	case ALLEGRO_KEY_Y:
		result=Key::Y;
		break;
	case ALLEGRO_KEY_Z:
		result=Key::Z;
		break;
	// ----------------------------- Numbers
	case ALLEGRO_KEY_0:
		result=Key::Key1;
		break;
	case ALLEGRO_KEY_1:
		result=Key::Key1;
		break;
	case ALLEGRO_KEY_2:
		result=Key::Key2;
		break;
	case ALLEGRO_KEY_3:
		result=Key::Key3;
		break;
	case ALLEGRO_KEY_4:
		result=Key::Key4;
		break;
	case ALLEGRO_KEY_5:
		result=Key::Key5;
		break;
	case ALLEGRO_KEY_6:
		result=Key::Key6;
		break;
	case ALLEGRO_KEY_7:
		result=Key::Key7;
		break;
	case ALLEGRO_KEY_8:
		result=Key::Key8;
		break;
	case ALLEGRO_KEY_9:
		result=Key::Key9;
		break;
	// ----------------------------- Numbers PAD
	case ALLEGRO_KEY_PAD_0:
		result=Key::KeyPad0;
		break;
	case ALLEGRO_KEY_PAD_1:
		result=Key::KeyPad1;
		break;
	case ALLEGRO_KEY_PAD_2:
		result=Key::KeyPad2;
		break;
	case ALLEGRO_KEY_PAD_3:
		result=Key::KeyPad3;
		break;
	case ALLEGRO_KEY_PAD_4:
		result=Key::KeyPad4;
		break;
	case ALLEGRO_KEY_PAD_5:
		result=Key::KeyPad5;
		break;
	case ALLEGRO_KEY_PAD_6:
		result=Key::KeyPad6;
		break;
	case ALLEGRO_KEY_PAD_7:
		result=Key::KeyPad7;
		break;
	case ALLEGRO_KEY_PAD_8:
		result=Key::KeyPad8;
		break;
	case ALLEGRO_KEY_PAD_9:
		result=Key::KeyPad9;
		break;
	// ----------------------------- Other
	case ALLEGRO_KEY_ESCAPE:
		result=Key::Escape;
		break;
	case ALLEGRO_KEY_MINUS:
		result=Key::Minus;
		break;
	case ALLEGRO_KEY_EQUALS:
		result=Key::Equals;
		break;
	case ALLEGRO_KEY_BACKSPACE:
		result=Key::Backspace;
		break;
	case ALLEGRO_KEY_TAB:
		result=Key::Tab;
		break;
	case ALLEGRO_KEY_SPACE:
		result=Key::Space;
		break;
	};
	
	return result;
}


/**
 *
 */
bool KeyEvent::getShiftPressed() const
{
	return m_ShiftPressed;
}


/**
 *
 */
void KeyEvent::setShiftPressed(bool pressed)
{
	m_ShiftPressed=pressed;
}


/**
 *
 */
bool KeyEvent::getAltPressed() const
{
	return m_AltPressed;
}


/**
 *
 */
void KeyEvent::setAltPressed(bool pressed)
{
	m_AltPressed=pressed;
}


/**
 *
 */
bool KeyEvent::getCtrlPressed() const
{
	return m_CtrlPressed;
}


/**
 *
 */
void KeyEvent::setCtrlPressed(bool pressed)
{
	m_CtrlPressed=pressed;
}


/**
 *
 */
bool KeyEvent::getMetaPressed() const
{
	return m_MetaPressed;
}


/**
 *
 */
void KeyEvent::setMetaPressed(bool pressed)
{
	m_MetaPressed=pressed;
}
	


// end of namespace
// ----------------
};

// end of namespace
// ----------------
};
