#include <iostream>
#include <sksat/optparse.hpp>

int func(int argc, char **argv){
	std::cout<<"option "<<argv[0]<<" : "<<argv[1]<<std::endl;
	return 1;
}

int main(int argc, char **argv){
	sksat::optparse op;
	op.add_opt('a', "aaa", "hoge", func);
	op.add_opt('b', "bbb", "fuga", func);
	op.add_opt('c', "neko", func);
	if(!op.parse(argc, argv)){
		std::cout<<"failed."<<std::endl;
	}
}
