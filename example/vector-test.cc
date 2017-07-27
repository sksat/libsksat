#include <iostream>
#include <sksat/math/vector.hpp>

template<typename T>
void print_vector(const sksat::math::vector<T> v){
	std::cout<<"x = " << v.get_x()
			<< ", y = " << v.get_y()
			<< ", z = " << v.get_z() << std::endl;
}

int main(int argc, char **argv){
	sksat::math::vector<> v1, v2;
	v1.set(0.5, 0.5, 0.5);
	v2.set(0.3, 0.3, 0.3);

//	v1 = v2;
	sksat::math::vector<> v3 = v1;
//	v3 = v1 + v2;
	v3 = v1 * 2.;

	std::cout<<"v1:"<<std::endl;
	print_vector(v1);
	std::cout<<"v2:"<<std::endl;
	print_vector(v2);
	std::cout<<"v3:"<<std::endl;
	print_vector(v3);

	return 0;
}
