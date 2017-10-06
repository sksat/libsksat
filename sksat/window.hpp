#ifndef SKSAT_WINDOW_HPP
#define SKSAT_WINDOW_HPP

#include <sksat/common.hpp>
#include <sksat/platform.hpp>

namespace sksat {

class window_base {
public:
	window_base() : opend(false), xsize(default_xsize), ysize(default_ysize) {}

	virtual void open() = 0;
	void open(size_t x, size_t y){ open(); set_size(x,y); }
	void open(sksat::string &t){ set_title(t); open(); }
	void open(sksat::string &t, size_t x, size_t y){ set_title(t); open(x,y); }

	virtual void close() = 0;

	virtual void show() = 0;

	void set_title(sksat::string &t){ title = t; update_title(t); }
	sksat::string get_title(){ return title; }

	virtual void set_size(size_t x, size_t y){
		xsize=x;
		ysize=y;
		if(opend)
			update_size(x,y);
	}
	void set_xsize(size_t x){ set_size(x, ysize); }
	void set_ysize(size_t y){ set_size(xsize, y); }
	size_t get_xsize() const { return xsize; }
	size_t get_ysize() const { return ysize; }
protected:
	virtual void update_title(sksat::string &t) = 0;
	virtual void update_size(size_t x, size_t y) = 0;
public:
	static size_t default_xsize, default_ysize;
	static size_t default_xpos, default_ypos;
protected:
	bool opend;
	size_t xsize, ysize;
	size_t xpos, ypos;
	sksat::string title;
};

size_t window_base::default_xsize = 100;
size_t window_base::default_ysize = 100;
size_t window_base::default_xpos  = 0;
size_t window_base::default_ypos  = 0;

}


#if defined(OS_WIN32)
	#error not implemented.
	#include <sksat/win32/window.hpp>
	namespace sksat{ using sksat::win32::window; }
#elif defined(OS_LINUX)
	#include <sksat/linux/window.hpp>
	namespace sksat{ using sksat::linux::window; }
#else
	#error not implemented.
#endif

#endif
