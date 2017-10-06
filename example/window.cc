#include <iostream>
#include <sksat/window.hpp>

using namespace sksat;

int main(int argc, char **argv){
try{
	window::default_xsize = 100;
	window::default_ysize = 200;
	window win;
	win.open();
	win.show();
	getchar();
	return 0;
}catch(sksat::string s){
	std::cout<<s;
}
}
