/**
 *
 */
#ifndef __HEADER_MOUSE_SCROLLER_EVENT_
#define __HEADER_MOUSE_SCROLLER_EVENT_

/**
 *
 */
namespace Gus
{

namespace EventLib
{

/**
 *
 */
class MouseScrollerEvent
{
public:
	MouseScrollerEvent();
	MouseScrollerEvent(ALLEGRO_EVENT ev);

	MouseScrollerEvent(const MouseScrollerEvent &source);

	virtual ~MouseScrollerEvent();

	int getScroller() const;

protected:
	int m_Scroller;
};

//
};

//
};

#endif /*__HEADER_MOUSE_SCROLLER_EVENT_*/
