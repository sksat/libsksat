#include <cstdio>
#include <string>

namespace sksat::math {

class gnuplot {
public:
	enum MODE {DEFAULT, PERSIST, };
	gnuplot() : gnuplot(DEFAULT) {}
	gnuplot(MODE m) : mode(m) {
		std::string arg("gnuplot");
		if(PERSIST) arg += " -persist";
		gp = popen(arg.c_str(), "w");
	}
	~gnuplot(){ pclose(gp); }

	void command(const char *com){
		fprintf(gp, "%s\n", com);
	}
	void command(std::string &com){
		command(com.c_str());
	}
	void set(const char *arg){
		fprintf(gp, "set %s\n", arg);
	}
	void set_grid()	{ set("grid"); }
	void flush()	{ fflush(gp); } 
	void plot(const char *arg){
		fprintf(gp, "plot %s\n", arg);
	}
	void plot()		{ plot(""); }
private:
	std::FILE *gp;
	MODE mode;
};

};
