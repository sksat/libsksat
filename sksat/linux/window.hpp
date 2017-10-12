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
	bool api_open(){
		char *argv = new char[1];
		disp = XOpenDisplay(NULL);
		root = DefaultRootWindow(disp);
		win = XCreateSimpleWindow(disp,
					DefaultRootWindow(disp),
					xpos, ypos, xsize, ysize,
					5, 0, 0);
		XSetStandardProperties(disp, win, title.c_str(), "icon", None, &argv, 1, nullptr);
		XSelectInput(disp, win, ExposureMask);
		opend = true;
	}

	void api_close(){
		XDestroyWindow(disp, win);
		XCloseDisplay(disp);
	}

	void api_show(){
		XMapRaised(disp, win);
		XFlush(disp);
	}

	void api_set_title(const char *t){
		if(XStoreName(disp, win, t) != 0) return;
		throw "error: x11::XStoreName";
	}

	void api_set_size(size_t x, size_t y){
		ASSERT(true, "not impl.");
	}

	inline void api_flush(){
		XFlush(disp);
	}

	inline bool api_step_loop(){
		XNextEvent(disp, &event);
		switch(event.type){
		case Expose:
			break;
		default:
			throw "not implemented event: sksat::linux:x11::window::api_step_loop()";
		}
		return true;
	}
private:
	x11::Display *disp;
	x11::Window root;
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
