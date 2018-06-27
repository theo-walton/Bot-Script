#ifndef INPUT_H
#define INPUT_H

#define LEFT_MOUSE_UP 0
#define LEFT_MOUSE_DOWN 1
#define RIGHT_MOUSE_UP 2
#define RIGHT_MOUSE_DOWN 3


#ifdef __cplusplus
extern "C"
{
#endif	
	void	MouseEvent(unsigned eventType, int x, int y);
	void	MousePosition(unsigned *x, unsigned *y);
	void	ImageAt(int x, int y, const char *file);
	void	Type(char c);
#ifdef __cplusplus
}
#endif

#endif
