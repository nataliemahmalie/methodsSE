

Label::Label(string value) : ControlBase(), value(value) {}; // problem with initialization list - to check and fix

Label::Label(short height, short width, short top, short left, Color textColor, Color backgroundColor, Border border, string value) :
     ControlBase(height, width, top, left, textColor, backgroundColor, border), value(value) {};

string Label::getValue()
{
    return this->value;
}

void Label::setValue(string value)
{
    this->value = value;
}


void Label::draw(Graphics& g, int x, int y, size_t z)
{
    if (!z)
        g.write(value);
/////////////////////////////////////////////////
}
