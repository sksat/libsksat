#include <iostream>
#include <sksat/cmdline.hpp>

int func(int argc, char **argv){
	std::cout<<"option "<<argv[0]<<" : ";
	if(argc>1)
		std::cout<<argv[1];
	std::cout<<std::endl;
	return 1;
}

int main(int argc, char **argv){
try{
	sksat::optparse op;
	op.add_opt('a', "aaa", "aaaa", func);
	op.add_opt('b', "bbb", "bbbb", func);

	bool flag_c;
	op.add_opt(flag_c, 'c', "ccc", "bool flag");

	std::string neko;
	op.add_opt(neko, 'n', "neko", "nekonyah");

	int hoge;
	op.add_opt(hoge, 'h', "hoge", "hogehoge");

	if(!op.parse(argc, argv)){
	//	std::cout<<"failed."<<std::endl;
		op.print_help();
		return -1;
	}

	if(flag_c) std::cout<<"c!!!"<<std::endl;
	std::cout<<"neko:"<<neko<<std::endl;
	std::cout<<"hoge:"<<hoge<<std::endl;
}catch(const char *msg){
	std::cout<<msg<<std::endl;
}
}
