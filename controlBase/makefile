	CXX = g++
else
	CXX = i686-w64-mingw32-g++
endif

OBJS =  main.o 

all: $(OBJS)
	$(CXX) $(OBJS) -o main.exe -static

run:
	wineconsole main.exe



