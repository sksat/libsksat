#ifndef SKSAT_LINUX_WINDOW_HPP_
#define SKSAT_LINUX_WINDOW_HPP_

#include <sksat/debug.hpp>
#include <X11/Xlib.h>
#include <X11/Xutil.h>

namespace sksat {
namespace linux {

class window : public sksat::window_base {
public:
	using sksat::window_base::open;
	void open(size_t x, size_t y){
		char *argv = new char[1];
		disp = XOpenDisplay(NULL);
		win = XCreateSimpleWindow(disp,
					DefaultRootWindow(disp),
					0, 0, 200, 100,
					5, 0, 0);
		XSetStandardProperties(disp, win, title.c_str(), "icon", None, &argv, 1, nullptr);
	}

	void close(){
		ASSERT(true, "not impl.");
	}

	void show(){
		// ASSERT(true, "not impl.");
		XMapRaised(disp, win);
		XFlush(disp);
	}

	void update_title(sksat::string &t){
		ASSERT(true, "not impl.");
	}

	void update_size(size_t x, size_t y){
		ASSERT(true, "not impl.");
	}
private:
	Display *disp;
	Window win;
	GC gc;
	XEvent event;
	XSizeHints hint;
};


#undef Display
#undef Window
#undef GC

}}
#endif
