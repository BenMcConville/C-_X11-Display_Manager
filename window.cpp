#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xos.h>
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#include <sys/utsname.h>

Display* dpy = XOpenDisplay(NULL);
Window win = XCreateSimpleWindow(dpy, RootWindow(dpy, DefaultScreen(dpy)), 10, 10, 660, 200, 1, BlackPixel(dpy, DefaultScreen(dpy)), WhitePixel(dpy, DefaultScreen(dpy)));	
Atom WM_DELETE_WINDOW = XInternAtom(dpy, "WM_DELETE_WINDOW", False);
	
//void line()	{
//	XDrawLine(dis, win, gc, 
//}
void setUp()	{
	XSelectInput(dpy, win, ExposureMask | KeyPressMask);
	XMapWindow(dpy, win);
	XSetWMProtocols(dpy, win, &WM_DELETE_WINDOW, 1);
	XEvent e;
}

int main(int argc, char** argv)
{
  setUp();
  XEvent e;
  
  while (1)	{
    XNextEvent(dpy, &e);
    if ((e.type == ClientMessage) && 
        (static_cast<unsigned int>(e.xclient.data.l[0]) == WM_DELETE_WINDOW))	{
      break;
    }
  }
 
  XDestroyWindow(dpy, win);
  XCloseDisplay(dpy);
  return 0;
}
