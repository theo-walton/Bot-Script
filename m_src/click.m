
#import <Foundation/Foundation.h>
#import <ApplicationServices/ApplicationServices.h>

#include "input.h"

void	MouseEvent(unsigned eventType, int x, int y)
{
	if (eventType > 3)
		return;
	
	CGEventType types[4] = {kCGEventLeftMouseUp, kCGEventLeftMouseDown,
				kCGEventRightMouseUp, kCGEventLeftMouseDown};

	CGPoint pt;
	pt.x = x;
	pt.y = y;
	CGEventRef event = CGEventCreateMouseEvent(NULL, types[eventType], pt, kCGMouseButtonRight);
	CGEventSetType(event, types[eventType]);
	CGEventPost(kCGHIDEventTap, event);
	CFRelease(event);
}

void	MousePosition(unsigned *x, unsigned *y)
{
	CGEventRef event = CGEventCreate(NULL);
	CGPoint cursor = CGEventGetLocation(event);
	CFRelease(event);
	*x = cursor.x;
	*y = cursor.y;
}
