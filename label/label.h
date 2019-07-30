#include <string>
#include "../controlBase/controlBase.h"
#include "../Graphics/Graphics.h"


using namespace std;

class Label: public ControlBase
{   
    private:
        string value;
    public:
        Label(string);
        Label(short height, short width, short top, short left, Color textColor, Color backgroundColor, Border border, string value);
        string getValue();
        void setValue(string);
        void draw(Graphics& g, int x, int y, size_t z);
        ~Label();
};
