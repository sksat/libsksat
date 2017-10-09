#include <iostream>
#include <sksat/file.hpp>

int main(int argc, char **argv){
	using namespace std;
	using namespace sksat;
	if(file::exist("file.cc"))
		cout<<"exist"<<endl;
	file f;
}
