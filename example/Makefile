CXX:= g++

CXXFLAGS = -g -O0 -std=c++11 -I../

SRC = cmdline.cc

default:
	$(CXX) $(CXXFLAGS) $(SRC) -o a.out

clean:
	rm -f a.*

vector:
	$(eval SRC=vector-test.cc)
	make


