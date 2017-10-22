#include <iostream>
#include <functional>
#include <vector>
#include <sksat/image.hpp>

template<typename T>
void print(sksat::image<T> &img){
	for(size_t y=0;y<10;y++){
		for(size_t x=0;x<10;x++){
			std::cout<<std::hex<<(uint32_t)img[y*10 + x].r<<" ";
		}
		std::cout<<std::endl;
	}
	std::cout<<"------------------------------"<<std::endl;
}

int main(int argc, char **argv){
try{
	auto red = sksat::rgba(0xff,0x00,0x00,0x00);
	sksat::image<sksat::rgba> img;
	img.init(10,10);
	print(img);
	img[3] = red; // 4番目の色を赤にする
	print(img);

	sksat::rgba &tmp = img[3]; // ４番目の色の参照を取ってくる
	std::cout<<"tmp.r = "<<(uint32_t)tmp.r<<std::endl;
	tmp.r = 0xaa; // img[3].r = 0xaa; と同じ
	print(img);

	sksat::rgba *img2;
	img2 = new sksat::rgba[10*10]; // 同じ大きさ

	for(size_t i=0;i<10*10;i++){ // コピーする
		img2[i] = img[i];
	}

	img2[0] = red; // コピー先を書き換える
	print(img); // 変化はない

	delete[] img2;

	std::vector<std::reference_wrapper<sksat::rgba>> img3; // 参照の動的配列(普通にnew/deleteだとダメ)
	for(size_t i=0;i<10*10;i++){ // 参照をコピー
		img3.push_back(img[i]);
	}
	img3[0].get() = red; // getがないとダメ
	print(img); // 書き換えられる

	img[100] = red;
	return 0;
}catch(const char *msg){
	std::cout<<msg<<std::endl;
}
}
