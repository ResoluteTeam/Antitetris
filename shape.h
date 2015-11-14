#ifndef SHAPE_H
#define SHAPE_H
enum shapeClass{
    I,
    Z,
    S,
    L,
    J,
    T,
    O
};

class Shape{

public:
        Shape(shapeClass type, int _x, int _y, int** field);
        ~Shape();
        bool** getShape();
        int getX();
        int getY();
        
        int getSizeX();
        int getSizeY();
        
        void setPosition(int x, int y);
        
        void draw();
        
private:
        int sizeX, sizeY;
        int** _field;
        bool** shapeMatrix;
        int _x, _y;
};

#endif
