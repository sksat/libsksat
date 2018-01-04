#ifndef SKSAT_MATH_GNUPLOT_HPP_
#define SKSAT_MATH_GNUPLOT_HPP_

#include <sksat/common.hpp>

namespace sksat {
namespace math {

class gnuplot {
public:
	enum MODE {DEFAULT, PERSIST, };
	gnuplot() : gnuplot(DEFAULT) {}
	gnuplot(MODE m) : mode(m) {
		sksat::string arg("gnuplot");
		if(mode == PERSIST) arg += " -persist";
		gp = sksat::popen(arg.c_str(), "w");
	}
	~gnuplot(){ pclose(gp); }

	void command(const char *com){
		sksat::fprintf(gp, "%s\n", com);
	}
	void command(sksat::string &com){
		command(com.c_str());
	}
	void set(const char *arg){
		sksat::fprintf(gp, "set %s\n", arg);
	}
	void set_grid()	{ set("grid"); }
	void flush()	{ fflush(gp); } 
	void plot(const char *arg){
		sksat::fprintf(gp, "plot %s\n", arg);
	}
	void plot()		{ plot(""); }
	void quit()		{ command("quit"); }
private:
	std::FILE *gp;
	MODE mode;
};

}
}
#endif
