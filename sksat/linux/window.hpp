#ifndef SKSAT_LINUX_WINDOW_HPP_
#define SKSAT_LINUX_WINDOW_HPP_

#include <sksat/debug.hpp>

namespace x11 {
extern "C" {
#include <X11/Xlib.h>
#include <X11/Xutil.h>
}
}

namespace sksat {
namespace linux {

using namespace x11;

class window : public sksat::window_base {
public:
	//using namespace ::x11;
	using sksat::window_base::open;
	void open(){
		char *argv = new char[1];
		disp = XOpenDisplay(NULL);
		win = XCreateSimpleWindow(disp,
					DefaultRootWindow(disp),
					xpos, ypos, xsize, ysize,
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
	x11::Display *disp;
	x11::Window win;
	x11::GC gc;
	x11::XEvent event;
	x11::XSizeHints hint;
};


#undef Display
#undef Window
#undef GC

}}
#endif
