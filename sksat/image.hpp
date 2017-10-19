#ifndef SKSAT_IMAGE_HPP_
#define SKSAT_IMAGE_HPP_

#include <sksat/common.hpp>
#include <sksat/color.hpp>

namespace sksat {

class image_base {
public:
	image_base() : xsize(default_xsize), ysize(default_ysize) {}
	virtual void init(size_t x, size_t y){ xsize = x; ysize = y; }
	virtual void init(){ xsize = default_xsize; ysize = default_ysize; }

	static size_t default_xsize, default_ysize;

	// 描画関数 継承先で”現在の色”を管理する
	virtual void draw_point(size_t x, size_t y) = 0;
	virtual void draw_line(size_t x0, size_t y0, size_t x1, size_t y1){
		int x, y, len, dx, dy;
		dx = x1-x0; dy = y1-y0;
		x = x0<<10; y = y0<<10;
		if(dx < 0) dx = -dx;
		if(dy < 0) dy = -dy;
		if(dx >= dy){
			len = dx+1;
			dx = 1024;
			if(x0 > x1) dx = -1 * dx;
			int tmp = -1;
			if(y0 <= y1) tmp=1;
			dy = ((y1-y0+tmp) << 10) / len;
		}else{
			len = dy+1;
			dy = 1024;
			if(y0 > y1) dy = -1 * dy;
			int tmp = -1;
			if(x0 <= x1) tmp=1;
			dx = ((x1-x0+tmp) << 10) / len;
		}
		for(int i=0;i<len;i++){
			draw_point(x>>10, y>>10);
			x+=dx; y+=dy;
		}
	}
protected:
	size_t xsize, ysize;
};

size_t image_base::default_xsize = 100;
size_t image_base::default_ysize = 100;

template<typename T>
class image : public image_base {
public:
	image() : data(nullptr) {}
	image(size_t x, size_t y) : data(nullptr) { init(x,y); }
	~image(){
		if(data != nullptr)
			delete[] data;
	}

	void init(size_t x, size_t y){
		image_base::init(x,y);
		if(data != nullptr)
			delete[] data;
		data = new T[xsize * ysize];
	}
	void init(){
		image_base::init();
		this->init(xsize, ysize);
	}

	void draw_point(size_t x, size_t y){
		if(x>=xsize || y>=ysize) throw "out of size";
		data[y*xsize + x] = col_now;
	}
	void draw_point(T &col, size_t x, size_t y){ col_now = col; draw_point(x,y); }
	void draw_line(T &col, size_t x0, size_t y0, size_t x1, size_t y1){ col_now = col; draw_line(x0,y0,x1,y1); }

	T col_now;
private:
	T *data;
};

template<>
class image<sksat::rgb24> : public image_base {
public:
	image() : data(nullptr) {}
	~image(){
		if(data!=nullptr)
			delete[] data;
	}

	void init(size_t x, size_t y){
		image_base::init(x,y);
		if(data != nullptr)
			delete[] data;
		data = new uint8_t[3 * xsize * ysize];
	}

	inline void draw_point(uint8_t r, uint8_t g, uint8_t b, size_t x, size_t y){
		if(x>=xsize || y>=ysize) throw "out of size";
		auto tmp = (xsize*y + x)*3;
		data[tmp  ] = r;
		data[tmp+1] = g;
		data[tmp+2] = b;
	}
	inline void draw_point(sksat::rgb24 &col, size_t x, size_t y){
		draw_point(col.r, col.g, col.b, x, y);
	}
	inline void draw_point(size_t x, size_t y){
		draw_point(col_now, x, y);
	}

	sksat::rgb24 col_now;
private:
	uint8_t *data;
};

}

#endif
