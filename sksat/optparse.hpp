#include <sksat/common.hpp>

namespace sksat {

using opt_func = int (*)(int, char**);
class optparse {
public:
	struct option {
		char s_opt;
		sksat::string l_opt, desc;
		opt_func func;
	};

	optparse() : argc(0), argv(nullptr) {}

	void add_opt(optparse::option o){
		opts.push_back(o);
	}

	void add_opt(char s_opt, sksat::string l_opt, sksat::string desc, opt_func func){
		option o = {
			.s_opt = s_opt,
			.l_opt = l_opt,
			.desc  = desc,
			.func  = func
		};

		add_opt(o);
	}

	void add_opt(char s_opt, sksat::string desc, opt_func func){
		option o = {
			.s_opt = s_opt,
			.l_opt = "",
			.desc  = desc,
			.func  = func
		};
		add_opt(o);
	}

	int search_short_opt(char c){
		for(int i=0;i<opts.size();i++){
			if(opts[i].s_opt == c) return i;
		}
		return -1;
	}

	int search_long_opt(sksat::string str){
		if(str == "") return -1;
		for(int i=0;i<opts.size();i++){
			if(opts[i].l_opt == str) return i;
		}
		return -1;
	}

	bool parse(int argc, char **argv){
		this->argc = argc;
		this->argv = argv;
		if(argc == 1) return false;
		argc--;
		argv++;
		for(int i=0;i<argc;i++){
			int opt_num = -1;
			if(argv[0][0] == '-'){ // option?
				if(argv[0][1] == '-'){ // long option
					opt_num = search_long_opt(argv[0]+2);
				}else{ // short option
					if(argv[0][1] != '\0'){
						if(argv[0][2] == '\0'){
							opt_num = search_short_opt(argv[0][1]);
						}
					}
				}
			}

			if(opt_num < 0){
				printf("\x1b[1m\x1b[33m");
				printf("%s: ", this->argv[0]);
				printf("\x1b[31m");
				printf("error: ");
				printf("\x1b[0m");
				printf("unrecognized option \'%s\'\n", argv[0]);
				exit(0);
			}

			opt_func f = opts[opt_num].func;
			int ret = f(argc-i, argv);
			i += ret;
			argv+=ret;

			argv++;
		}
		return true;
	}

private:
	int argc;
	char **argv;
	sksat::vector<option> opts;
};

}
