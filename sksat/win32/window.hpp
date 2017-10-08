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
	bool api_open(){
		hInst = GetModuleHandle("");
		hWnd = CreateWindow("STATIC", "fuga",
				WS_CAPTION,
				xpos, ypos,
				xsize, ysize,
				nullptr, nullptr,
				hInst, nullptr);
		if(hWnd == nullptr)
			return false;
		return true;
	}

	void api_close(){
		ASSERT(true, "not implemented.");
	}

	void api_show(){
		ShowWindow(hWnd, SW_SHOW);
	}

	void api_set_title(const char *t){
		ASSERT(true, sksat::string("not implemented: ") + t);
	}

	void api_set_size(size_t x, size_t y){
		ASSERT(true, "not implemented.");
	}
private:
	HINSTANCE hInst;
	HWND hWnd;
};

}
}

#endif
