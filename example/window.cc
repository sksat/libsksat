#include <iostream>
#include <sksat/window.hpp>

using namespace sksat;

int main(int argc, char **argv){
try{
	window win;
	win.open();
	win.show();
	win.loop();
//	getchar();
	return 0;
}catch(sksat::string s){
	std::cout<<s;
}
}
