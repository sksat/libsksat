CXX:= g++

CXXFLAGS = -g -O0 -std=c++11 -I../

BRANCH := $(shell git rev-parse --abbrev-ref HEAD)
LATEST := $(shell ls -1t *.cc | head -1)
COMMAND = build

all:
ifeq ($(BRANCH),master)
	$(eval TARGET=$(LATEST:.cc=))
else
ifeq ($(BRANCH),develop)
	$(eval TARGET=$(LATEST:.cc=))
else
	$(eval TARGET=$(shell echo $(BRANCH) | sed -e 's/^.*\/\([a-z|\/]*\).*$$/\1/'))
endif
endif
ifeq ($(COMMAND),build)
	$(CXX) $(CXXFLAGS) $(TARGET).cc -o $(TARGET) $(LDFLAGS)
endif
ifeq ($(COMMAND),clean)
	rm -f $(TARGET)
endif
ifeq ($(COMMAND),run)
	make COMMAND=build
	./$(TARGET)
endif

run:
	make COMMAND=run

clean:
	make COMMAND=clean
