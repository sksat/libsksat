#include <iostream>
#include <sksat/window.hpp>

using namespace sksat;

int main(int argc, char **argv){
try{
	window win;
	win.open();
	win.show();
	win.set_title("hoge");
	win.flush();

	for(int i=0;;i++){
		if(i%2==0)
			win.move(100,100);
		else
			win.move(0,0);
		win.flush();
		getchar();
	}

	win.step_loop();
	return 0;
}catch(const char *s){
	std::cout<<s;
}catch(std::string s){
	std::cout<<s;
}
}
