#include <sksat/color.hpp>

int main(){
	sksat::rgb rgb;
	rgb.r = 0xff;
	rgb.g = 0xff;
	rgb.b = 0xff;

	sksat::rgba rgba;
	rgba.r = 0xff;

	rgb = rgba;
	rgba = rgb;

	sksat::color col;
	col = rgba;
}
