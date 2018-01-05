#ifndef SKSAT_FILE_HPP_
#define SKSAT_FILE_HPP_

#include <sksat/common.hpp>
#include <sys/stat.h>

namespace sksat {

class file {
public:
	file() : fp(nullptr), size(0x00) { init(); }
	file(const std::string &name) : fp(nullptr), size(0x00), name(name) { init(); }
	~file(){ close(); }

	enum class mode : uint8_t {
		r  = 0b0000,
		w  = 0b0001,
		a  = 0b0010,
		b  = 0b0100,
		rw = r | w,
		rb = r | b,
		wb = w | b,
		ab = a | b,
		ar = a | r,
		rwb= rw| b,
		arb= ar| b
	};
protected:
	virtual void init(){
		flg_opend	= false;
		flg_new		= true;
		// デフォルトでは"r+"
		m_mode		= mode::rw;
	}

	std::string name;
	std::FILE *fp;
	size_t size;
	bool flg_opend, flg_new;
	mode m_mode;
public:
	bool exist() const { return exist(name); }

	bool open(const std::string &name, mode mode_){
		if(flg_opend)
			return false;

		this->name	= name;
		this->m_mode	= mode_;

		if(exist())
			flg_new = false;

		char fm[3] = {'\0'};
		auto m = static_cast<uint8_t>(mode_); // TODO: enum classのoperator|,operator&
		if(m & static_cast<uint8_t>(mode::w)){
			fm[0] = 'w';
			if(m & static_cast<uint8_t>(mode::r))
				fm[1] = '+';
		}else if(m & static_cast<uint8_t>(mode::a)){
			fm[0] = 'a';
			if(m & static_cast<uint8_t>(mode::r))
				fm[1] = '+';
		}else if(m & static_cast<uint8_t>(mode::r)){
			fm[0] = 'r';
		}else{
			throw "error";
		}

		if(m & static_cast<uint8_t>(mode::b)){
			if(fm[1] == '\0')
				fm[1] = 'b';
			else
				fm[2] = 'b';
		}

		fp = std::fopen(name.c_str(), fm);
		flg_opend = true;
		if(fp == nullptr)
			flg_opend = false;
		return flg_opend;
	}
	bool open(const std::string &name){ open(name, this->m_mode); }
	bool open(mode mode_){ open(this->name, mode_); }
	bool open(){ open(this->name, this->m_mode); }

	bool try_open(mode try_mode){
		if(static_cast<uint8_t>(m_mode) & static_cast<uint8_t>(try_mode))
			return open();
		// TODO: エラー処理
		return false;
	}

	void close(){
		if(!flg_opend) return;
		auto ret = fclose(fp);
		flg_opend = false;
		if(ret == EOF){
			//TODO: 正常に終了しなかった場合
		}
	}

	template<typename T>
	T read(){
		std::stringstream ss;
		ss << read<std::string>();
		T v;
		ss >> v;
		return v;
	}

	template<typename T>
	void write(const T &v){
		std::stringstream ss;
		ss << v;
		write<std::string>(ss.str());
	}

	static bool exist(const std::string &fname){
		struct stat st;
		if(stat(fname.c_str(), &st) == 0)
			return true;
		return false;
	}
};

template<typename T>
file& operator<<(file &f, const T &v){
	f.write(v);
	return f;
}

template<>
std::string file::read<std::string>(){
	if(!flg_opend){
		if(!try_open(mode::r))
			return {};
	}

	std::string str;
	for(;;){
		char c = std::fgetc(fp);
		if(c == EOF || c == '\n')
			return str;
		str.push_back(c);
	}
}

template<>
void file::write<std::string>(const std::string &str){
	if(!flg_opend){
		if(!try_open(mode::w) && !try_open(mode::a))
			return;
	}
	std::fputs(str.c_str(), fp);
}

}

#endif
