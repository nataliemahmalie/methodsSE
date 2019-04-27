ifeq ($(OS), Windows_NT)
	CXX = g++
else
	CXX = i686-w64-mingw32-g++
endif

OBJS =  main.cpp  TextBox.cpp

all: $(OBJS)
	$(CXX) $(OBJS) -o main.exe -static

run:
	wineconsole main.exe

