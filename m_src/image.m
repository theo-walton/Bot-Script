
#import <Foundation/Foundation.h>
#import <ApplicationServices/ApplicationServices.h>

#include "input.h"

#import <CoreServices/CoreServices.h>
#import <ImageIO/ImageIO.h>

void	CGImageWriteToFile(CGImageRef image, NSString *path)
{
	CFURLRef url = (__bridge CFURLRef)[NSURL fileURLWithPath:path];
	CGImageDestinationRef destination = CGImageDestinationCreateWithURL(url, kUTTypePNG, 1, NULL);

	CGImageDestinationAddImage(destination, image, nil);
	CGImageDestinationFinalize(destination);
	CFRelease(destination);
}

CGImageRef	captureRect(int x, int y)
{
	const int size = 40;
	CGRect rect;
	CGPoint p = {x - size / 2, y - size / 2};
	CGSize s = {size, size};
	rect.origin = p;
	rect.size = s;

	return CGDisplayCreateImageForRect(CGMainDisplayID(), rect);		
}

void	ImageAt(int x, int y, const char *file)
{
	CGImageRef im = captureRect(x, y);	
	NSString *path = @(file);

	CGImageWriteToFile(im, path);
}
