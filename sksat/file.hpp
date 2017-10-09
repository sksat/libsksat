#ifndef SKSAT_FILE_HPP_
#define SKSAT_FILE_HPP_

#include <sksat/common.hpp>
#include <stdio.h>
#include <sys/stat.h>

namespace sksat {

class file {
public:
	enum class mode {
		read_binary=0, rb=0,
		write_binary=1, wb=1,
		read_text=2, r=2,
		write_text=3, w=3,
	};

	file() : data(nullptr) { init(); } // initでdelete食らわないようにしっかりnullptr
	~file(){
		if(fp!=nullptr)
			fclose(fp);
	}

	void init(){
		fmode = mode::r;
		opend = false;
		flg_new = false;
		name = "";
		fp = nullptr;
		if(fp != nullptr)
			fclose(fp);
		size = 0;
		if(data != nullptr)
			delete data;
		data = nullptr;
	}

	static bool exist(const char *fname){
		struct stat st;
		if(stat(fname, &st) == 0)
			return true;
		return false;
	}

	bool exist() const { return sksat::file::exist(name.c_str()); }

	bool open(){
		if(!exist())
			flg_new = true;
		char fm[3] = {'\0'};
		switch(fmode){
		case mode::rb:
			fm[0] = 'r';
			fm[1] = 'b';
		case mode::wb:
			fm[0] = 'w';
			fm[1] = 'b';
		case mode::r:
			fm[0] = 'r';
		case mode::w:
			fm[0] = 'w';
		default:
			throw "error!";
		}
		fp = fopen(name.c_str(), fm);
		if(fp == nullptr)
			return false;
		opend = true;
		return true;
	}

	bool open(const char *fname){ set_name(fname); open(); }
	bool open(sksat::string &fname){ set_name(fname); open(); }

	void close(){
		if(fp != nullptr)
			fclose(fp);
		opend = false;
	}

	void set_name(const char *fname){ sksat::string s=fname; set_name(s); }
	void set_name(sksat::string &fname){
		if(opend)
			throw "opend";
		this->name = fname;
	}

	sksat::string get_name() const { return name; }
protected:
	mode fmode;
	bool opend;
	bool flg_new;
	sksat::string name;
	FILE *fp;
	size_t size;
	char *data;
};

}

#endif
