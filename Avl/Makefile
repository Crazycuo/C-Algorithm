CC = gcc
CXX = g++
CFLAGS = -g -Wall -fPIC -std=c++11

INCLUDE = ./include
SRC = ./src/*.cpp
TARGET = ./lib/libavl_node.so
BINDIR = .
OBJDIR = bin/obj
LDFLAGS = -shared
LIBS = -L ./lib -lstdc++ -lpthread -lavl_node #-lavl_node refers to libavl_node.so

TESTDIR = ./Test
TESTSRC = $(wildcard $(TESTDIR)/*.cpp) #扩展通配符
TESTOBJ = $(patsubst $(TESTDIR)/%.cpp,$(OBJDIR)/%.o,$(filter %.cpp,$(TESTSRC)))#替换通配符
TESTTAR = $(patsubst $(TESTDIR)/%.cpp,$(BINDIR)/%,$(filter %.cpp,$(TESTSRC)))#替换通配符

all: $(TARGET)
$(TARGET): pre
	$(CXX) $(CFLAGS) -o $(TARGET) $(SRC) -I $(INCLUDE) $(LDFLAGS)	
	@echo "generate the shared library"
pre:
	test -d lib || mkdir lib
	test -d bin || mkdir -p bin/obj

test: $(TESTTAR)
$(BINDIR)/%: $(OBJDIR)/%.o
	$(CXX) $(CFLAGS) -o $@ $^ -I $(INCLUDE) $(LIBS)
$(OBJDIR)/%.o: $(TESTDIR)/%.cpp
	$(CXX) $(CFLAGS) -o $@ -c $^ -I $(INCLUDE) $(LIBS)

.PHONY: clean
clean: 
	rm -rf bin 
	rm -rf lib
	rm $(TESTTAR)
