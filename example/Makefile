CXX:= g++

CXXFLAGS = -g -O0 -std=c++11
CXXFLAGS += -I../

SRC = vector-test.cc

default:
	$(CXX) $(CXXFLAGS) $(SRC) -o a.out

clean:
	rm -fr a.out

vector:
	$(eval SRC=vector-test.cc)
	make


