
RM = rm -f
CREATE_SO = g++ -shared
CXX = g++
CXXFLAGS = -fPIC -Wall -g -DNDEBUG 
INCLUDES = -I../../pybind11/include -I/usr/include/python3.6m
LDFLAGS = #-lpython3.6m
LDPATH =
VPATH = 

SOURCES = $(shell ls *.cpp)
OBJECTS = $(SOURCES:%.cpp=%.o)
DYNAMICLIB = hello.so

all: $(DYNAMICLIB)
	@echo "DYNAMICLIB = $(DYNAMICLIB)" 

.PHONY: clean
clean:
	$(RM) $(DYNAMICLIB) $(OBJECTS)

$(OBJECTS): %.o: %.cpp
	$(CXX) -o $@ -c $(CXXFLAGS) $(INCLUDES) $<

$(DYNAMICLIB): $(OBJECTS)
	$(CREATE_SO) -o $(DYNAMICLIB) $(OBJECTS) $(LDFLAGS)

