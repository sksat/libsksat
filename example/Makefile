CXX:= g++

CXXFLAGS = -g -O0 -std=c++11 -I../

SRC = window.cc

default:
	$(CXX) $(CXXFLAGS) $(SRC) -o a.out -lX11

clean:
	rm -fr a.out

vector:
	$(eval SRC=vector-test.cc)
	make


