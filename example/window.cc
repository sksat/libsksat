#include <iostream>
#include <sksat/window.hpp>

using namespace sksat;

int main(int argc, char **argv){
try{
	window win;
	win.open();
	win.show();
	win.set_title("hoge");
	auto red = sksat::color(0xff,0x00,0x00);
	for(int x=0;x<50;x++){
		win.draw_point(red, x, 50); // （ヽ *ﾟ▽ﾟ*）ノわーい！ 線が出るよ！ ( *ﾟ▽ﾟ* っ)З ==3
	}
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
