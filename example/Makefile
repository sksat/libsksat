CXX:= g++

CXXFLAGS = -g -O0 -std=c++11 -I../

SRC = window.cc

default:
	$(CXX) $(CXXFLAGS) $(SRC) -mwindows

clean:
	rm -fr a.*

vector:
	$(eval SRC=vector-test.cc)
	make


