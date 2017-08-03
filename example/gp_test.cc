#include "../sksat/math/gnuplot.hpp"

int main(int argc, char **argv){
	sksat::math::gnuplot gp(sksat::math::gnuplot::PERSIST);

	gp.plot("sin(x)");
	return 0;
}
