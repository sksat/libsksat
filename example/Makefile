CXX:= g++

CXXFLAGS = -g -O0 -std=c++11 -I../

SRC = endian.cc

default:
	$(CXX) $(CXXFLAGS) $(SRC) -lX11

clean:
	rm -fr a.*

vector:
	$(eval SRC=vector-test.cc)
	make


