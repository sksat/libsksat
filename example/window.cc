#include <iostream>
#include <sksat/window.hpp>

using namespace sksat;

int main(int argc, char **argv){
try{
	window win;
	win.open();
	win.show();
	win.set_title("hoge");
	win.loop();
	return 0;
}catch(const char *s){
	std::cout<<s;
}
}
