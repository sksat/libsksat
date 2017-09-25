#include <iostream>
#include <sksat/optparse.hpp>

int func(int argc, char **argv){
	std::cout<<"option "<<argv[0]<<" : "<<argv[1]<<std::endl;
	return 1;
}

int main(int argc, char **argv){
try{
	sksat::optparse op;
	op.add_opt('a', "aaa", "aaaa", func);
	op.add_opt('b', "bbb", "bbbb", func);
	std::string neko;
	op.add_opt(neko, 'n', "neko", "nekonyah");
	int hoge;
	op.add_opt(hoge, 'h', "hoge", "hogehoge");

	op.parse(argc, argv);

	std::cout<<"neko:"<<neko<<std::endl;
	std::cout<<"hoge:"<<hoge<<std::endl;
}catch(const char *msg){
	std::cout<<msg<<std::endl;
}
}
