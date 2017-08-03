#include <string>
#include <sksat/common.hpp>

namespace sksat {
namespace math {

class gnuplot {
public:
	enum MODE {DEFAULT, PERSIST, };
	gnuplot() : gnuplot(DEFAULT) {}
	gnuplot(MODE m) : mode(m) {
		std::string arg("gnuplot");
		if(mode == PERSIST) arg += " -persist";
		gp = sksat::popen(arg.c_str(), "w");
	}
	~gnuplot(){ pclose(gp); }

	void command(const char *com){
		std::fprintf(gp, "%s\n", com);
	}
	void command(std::string &com){
		command(com.c_str());
	}
	void set(const char *arg){
		std::fprintf(gp, "set %s\n", arg);
	}
	void set_grid()	{ set("grid"); }
	void flush()	{ fflush(gp); } 
	void plot(const char *arg){
		std::fprintf(gp, "plot %s\n", arg);
	}
	void plot()		{ plot(""); }
	void quit()		{ command("quit"); }
private:
	std::FILE *gp;
	MODE mode;
};

}
}
