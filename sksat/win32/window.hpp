#ifndef SKSAT_WIN32_WINDOW_HPP_
#define SKSAT_WIN32_WINDOW_HPP_

#include <sksat/debug.hpp>

namespace win32 {
extern "C" {
	#include <windows.h>
}
}

#undef NULL

namespace sksat {
namespace win32 {

using namespace ::win32;

class window : public sksat::window_base {
public:
	void open(){
		hInst = GetModuleHandle("");
		hWnd = CreateWindow("STATIC", "fuga",
				WS_CAPTION,
				xpos, ypos,
				xsize, ysize,
				nullptr, nullptr,
				hInst, nullptr);
		if(hWnd == nullptr)
			ASSERT(true, "error");
	}

	void close(){
		ASSERT(true, "not implemented.");
	}

	void show(){
		ShowWindow(hWnd, SW_SHOW);
	}

	void update_title(sksat::string &t){
		ASSERT(true, sksat::string("not implemented: ") + t);
	}

	void update_size(size_t x, size_t y){
		ASSERT(true, "not implemented.");
	}
private:
	HINSTANCE hInst;
	HWND hWnd;
};

}
}

#endif
