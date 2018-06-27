
#import <Foundation/Foundation.h>
#import <ApplicationServices/ApplicationServices.h>

#include <Carbon/Carbon.h>
#include "input.h"

void	Type(char c)
{

	CGKeyCode keycode[10] = {kVK_ANSI_0,
				 kVK_ANSI_1,
				 kVK_ANSI_2,
				 kVK_ANSI_3,
				 kVK_ANSI_4,
				 kVK_ANSI_5,
				 kVK_ANSI_6,
				 kVK_ANSI_7,
				 kVK_ANSI_8,
				 kVK_ANSI_9};
	
	if (c < '0' || c > '9') // cba to support non digits
		return;
	
	CGEventRef event = CGEventCreateKeyboardEvent(NULL, keycode[c - '0'], true);
	CGEventPost(kCGSessionEventTap, event);
	CFRelease(event);

	event = CGEventCreateKeyboardEvent(NULL, keycode[c - '0'], false);
	CGEventPost(kCGSessionEventTap, event);
	CFRelease(event);
}
