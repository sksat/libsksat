#ifndef SKSAT_FILE_HPP_
#define SKSAT_FILE_HPP_

#include <sksat/common.hpp>
#include <stdio.h>
#include <sys/stat.h>

namespace sksat {

class file {
public:
	enum mode {
		read_binary=0, rb=0,
		write_binary=1, wb=1,
		read_text=2, r=2,
		write_text=3, w=3,
	};

	file() : data(nullptr) { init(); } // initでdelete食らわないようにしっかりnullptr
	~file(){
		close();
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
			break;
		case mode::wb:
			fm[0] = 'w';
			fm[1] = 'b';
			break;
		case mode::r:
			fm[0] = 'r';
			break;
		case mode::w:
			fm[0] = 'w';
			break;
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
		if(!opend) return;
		if(fp == nullptr) return;
		int ret = fclose(fp);
//		if(ret == EOF) // error
		opend = false;
	}

	void set_name(const char *fname){ sksat::string s=fname; set_name(s); }
	void set_name(sksat::string &fname){
		if(opend)
			throw "opend";
		this->name = fname;
	}

	sksat::string get_name() const { return name; }

	virtual void set_mode(sksat::file::mode m){ if(!opend) fmode = m; }
	sksat::file::mode get_mode(){ return fmode; }
protected:
	mode fmode;
	bool opend;
	bool flg_new;
	sksat::string name;
	FILE *fp;
	size_t size;
	char *data;
};

class text_file : public file {
public:
	void set_mode(const sksat::file::mode m){
		if((m != file::r) && (m != file::w)){
			throw "cannot set binary mode!";
		}
		file::set_mode(m);
	}
};

class binary_file : public file {
public:
	void set_mode(const file::mode m){
		if((m != file::rb) && (m != file::wb)){
			throw "cannot set text mode!";
		}
		file::set_mode(m);
	}
};

using txtfile = text_file;
using binfile = binary_file;

} // namespace sksat

#endif
