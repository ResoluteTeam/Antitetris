#include "button.h"
        
Button::Button(){

}

void Button::setCaption(std::string text){
    caption.setText(text);
}

void Button::setPosition(int x, int y){
    _x = x;
    _y = y;
    caption.setPosition(_x + 10, _y + 10);
}

void Button::setColor(int bkcolor, int textcolor){
    color = bkcolor;
    textColor = textcolor;
    caption.setColor(color, textColor);
}
        
void Button::draw(){
    setfillstyle(SOLID_FILL, color);
    bar(_x, _y, _x + 265, _y + 120);
    rectangle(_x, _y, _x + 265, _y + 120);
    caption.draw();
}
