#include <iostream>
#include <sksat/file.hpp>

int main(int argc, char **argv){
	using sksat::file;
	file f("test.txt");
	if(f.exist()){
		std::cout<<"file exist"<<std::endl;
		f.open(file::mode::a);
	}
	f<<"aaa";
	return 0;
}
