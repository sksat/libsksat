#include <cstdio>
#include <iostream>
#include <string>
#include <sksat/shell.hpp>

int func(std::string &s){
	std::cout<<"command: "<<s<<std::endl;
	return 0;
}

int main(int argc, char **argv){
	sksat::shell sh;
	if(argc == 2){
		FILE *in = std::fopen(argv[1], "r");
		sh.set_infile(in);
	}
	sh.set_prompt("$ ");
	sh.set_comment("//");
	sh.set_comment("/*", "*/");
	sh.default_func = func;
	sh.loop();
}
