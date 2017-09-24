CXX:= g++

CXXFLAGS = -g -O0 -std=c++11 -I../

SRC = optparse.cc

default:
	$(CXX) $(CXXFLAGS) $(SRC) -o a.out

clean:
	rm -fr a.out

vector:
	$(eval SRC=vector-test.cc)
	make


