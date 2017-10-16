#include <iostream>
#include <sksat/file.hpp>

int main(int argc, char **argv){
try{
	using namespace std;
	using namespace sksat;
	if(file::exist("test.txt"))
		cout<<"exist"<<endl;
	txtfile f;
	f.set_name("test.txt");
	f.set_mode(sksat::file::w);
	f.open();
	f.close();
}catch(const char *e){
	std::cout<<e<<std::endl;
}

}
