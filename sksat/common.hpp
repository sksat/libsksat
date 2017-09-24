#ifndef SKSAT_COMMON_HPP_
#define SKSAT_COMMON_HPP_

#include <cstdio>
#undef popen
#undef pclose

namespace sksat
{
	using ::FILE;
	using ::fpos_t;

	using ::clearerr;
	using ::fclose;
	using ::feof;
	using ::ferror;
	using ::fflush;
	using ::fgetc;
	using ::fgetpos;
	using ::fgets;
	using ::fopen;
	using ::fprintf;
	using ::fputc;
	using ::fputs;
	using ::fread;
	using ::freopen;
	using ::fscanf;
	using ::fseek;
	using ::fsetpos;
	using ::ftell;
	using ::fwrite;
	using ::getc;
	using ::getchar;

	using ::popen;
	using ::pclose;
}

#ifndef NO_STL
	#include <vector>
	#include <string>
	namespace sksat {
		using std::vector;
		using std::string;
	}
#endif

#endif
