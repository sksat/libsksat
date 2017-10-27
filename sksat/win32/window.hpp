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

inline COLORREF col2colr(const sksat::color &col){
	return ((DWORD)(((BYTE)(col.r) | ((WORD)(col.g) << 8)) | (((DWORD)(BYTE)(col.b)) << 16)));
}

class window : public sksat::window_base {
public:
	window() : sksat::window_base(), bmp_created(false) {}

	bool api_open(){
		hinst = GetModuleHandle("");

		WNDCLASSEX wcx;
		wcx.cbSize		= sizeof(wcx);
		wcx.lpszClassName	= "sksat::win32::window";
		wcx.lpszMenuName	= nullptr;
		wcx.style		= CS_HREDRAW | CS_VREDRAW;
		wcx.lpfnWndProc		= window::WndProcWrapper;
		wcx.hbrBackground	= (HBRUSH)GetStockObject(WHITE_BRUSH);
		wcx.hIcon		= nullptr;
		wcx.hIconSm		= nullptr;
		wcx.hCursor		= nullptr;
		wcx.hInstance		= hinst;
		wcx.cbClsExtra		= 0;
		wcx.cbWndExtra		= 0;

		if(RegisterClassEx(&wcx) == 0) return false;

		hwnd = CreateWindow(wcx.lpszClassName,
				"fuga",
				WS_CAPTION,
				xpos, ypos,
				xsize, ysize,
				nullptr, nullptr,
				hinst,
				this);
		if(hwnd == nullptr)
			return false;
		create_bmp(xsize, ysize);
		return true;
	}

	void api_close(){
		ASSERT(true, "not implemented.");
	}

	void api_show(){
		ShowWindow(hwnd, SW_SHOW);
	}

	void api_set_title(const char *t){
		// ASSERT(true, sksat::string("not implemented: ") + t);
		SetWindowText(hwnd, t);
	}

	void api_set_size(size_t x, size_t y){
		MoveWindow(hwnd, xpos, ypos, x, y, false);
	}

	void api_move(size_t x, size_t y){
		ASSERT(true, "not implemented.");
	}

	void api_flush(){
		//RedrawWindow(hwnd, nullptr, nullptr, RDW_INTERNALPAINT);
		InvalidateRect(hwnd, nullptr, false);
	}

	inline void api_draw_point(const sksat::color &col, size_t x, size_t y){
//		HDC hdc; PAINTSTRUCT ps;
//		hdc = BeginPaint(hwnd, &ps);
		SelectObject(hdc, GetStockObject(BLACK_BRUSH));
		Rectangle(hdc, 0, 0, x, y);
		SetPixel(hdc, x, y, col2colr(col));
//		EndPaint(hwnd, &ps);
	}

	inline bool api_step_loop(){
		if(GetMessage(&msg, nullptr, 0, 0) > 0){
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
private:
	void create_bmp(size_t x, size_t y){
		HDC hdc = GetDC(hwnd);
		if(bmp_created) DeleteObject(hbmp);
		hbmp = CreateCompatibleBitmap(hdc, x, y);
		this->hdc = CreateCompatibleDC(hdc);
		SelectObject(this->hdc, hbmp);
	}

	static LRESULT CALLBACK WndProcWrapper(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp){
		// http://clown.hatenablog.jp/entry/20110811/win32_api_wndproc の方式の方が良さそうなのであとで変更する
		window* this_ptr = (window*)GetWindowLong(hwnd, GWL_USERDATA);
		if(this_ptr == nullptr){ // thisポインタを取得できなかった
			if(msg == WM_CREATE){
				this_ptr = reinterpret_cast<window*>((reinterpret_cast<LPCREATESTRUCT>(lp))->lpCreateParams);
				if(this_ptr != nullptr)
					return this_ptr->WndProc(hwnd, msg, wp, lp);
					SetWindowLong(hwnd, GWL_USERDATA, (LONG)this_ptr);
			}else{
	//			ASSERT(true, "error");
			}
		}else{
			return this_ptr->WndProc(hwnd, msg, wp, lp);
		}
		return DefWindowProc(hwnd, msg, wp, lp);
	}

	LRESULT WndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp){
		HDC hdc;
		PAINTSTRUCT ps;
		switch(msg){
		case WM_CREATE:
			MessageBox(hwnd, "created", "hoge", MB_ICONINFORMATION);
			break;
		case WM_PAINT:
			MessageBox(hwnd, "", "", MB_OK);
			hdc = BeginPaint(hwnd, &ps);
			BitBlt(hdc, 0, 0, xsize, ysize, this->hdc, 0, 0, SRCCOPY);
			EndPaint(hwnd, &ps);
			break;
		default:
			break;
		}
		return DefWindowProc(hwnd, msg, wp, lp);
	}

	bool bmp_created;

	HINSTANCE hinst;
	HWND hwnd;
	HBITMAP hbmp; // double buffering
	HDC hdc;
	MSG msg;
};

}
}

#endif
