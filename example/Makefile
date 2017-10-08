CXX:= g++

CXXFLAGS = -g -O0 -std=c++11 -I../

SRC = window.cc

default:
	$(CXX) $(CXXFLAGS) $(SRC) -o a.exe

clean:
	rm -fr a.exe

vector:
	$(eval SRC=vector-test.cc)
	make


