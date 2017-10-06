#include <iostream>
#include <sksat/window.hpp>

int main(int argc, char **argv){
try{
	sksat::window win;
	win.open();
	win.show();
	getchar();
	return 0;
}catch(sksat::string s){
	std::cout<<s;
}
}
