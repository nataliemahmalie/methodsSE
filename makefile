CXX = i686-w64-mingw32-g++
CPPFLAGS = -std=c++1z -static -g
OBJS += Common/Button.cpp Common/CheckList.cpp  Common/ComboBox.cpp Common/Control.cpp Common/EventEngine.cpp Common/Graphics.cpp Common/Label.cpp Common/MessageBoxx.cpp Common/NumericBox.cpp Common/Panel.cpp Common/RadioBox.cpp Common/TextBox.cpp FinalProject/main.cpp

%.o: %.cpp
	$(CXX) $(CPPFLAGS) -c $< -o $@

all: $(OBJS)
	$(CXX) $(CPPFLAGS) $(OBJS) -o final.exe
clean:
	rm -f $(OBJS)
	rm -f *.exe


