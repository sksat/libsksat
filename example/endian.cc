#include <iostream>
#include <sksat/endian.hpp>

int main(int argc, char **argv){
	if(sksat::endian::now == sksat::endian::little)
		std::cout<<"little"<<std::endl;
	if(!sksat::endian::is_big())
		std::cout<<"not big"<<std::endl;
	if(sksat::endian::is_little())
		std::cout<<"little"<<std::endl;
	std::cout<<sksat::endian::which().to_int()<<std::endl;
	std::cout<<sksat::endian::which().to_str()<<std::endl;
}
