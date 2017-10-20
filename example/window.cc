#include <iostream>
#include <sksat/window.hpp>

using namespace sksat;

int main(int argc, char **argv){
try{
	window win;
	win.open();
	win.set_title("hoge");
	auto red = sksat::color(0xff,0x00,0x00);
	auto green = sksat::color(0x00, 0xff, 0x00);
	auto blue = sksat::color(0x00, 0x00, 0xff);
	win.draw_line(red, 0, 0, 30, 50); // （ヽ *ﾟ▽ﾟ*）ノわーい！ 線が出るよ！ ( *ﾟ▽ﾟ* っ)З ==3
	win.draw_rect(red, 50, 50, 90, 90, true);
	win.draw_rect(blue, 55, 55, 85, 85, false);
	win.flush();
	win.show();
	win.loop();
	return 0;
}catch(const char *s){
	std::cout<<s;
}catch(std::string s){
	std::cout<<s;
}
}
