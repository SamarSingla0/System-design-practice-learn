#include <iostream>
using namespace std;

class TwoDShape {
public:
    virtual double area() = 0;
};

class ThreeDShape : public TwoDShape {
public:
    virtual double volume() = 0;
};

class Square : public TwoDShape {
private:
    double side;
public:
    Square(double s) : side(s) {}
    double area() override {
        return side * side;
    }
};

class Rectangle : public TwoDShape {
private:
    double length, width;
public:
    Rectangle(double l, double w) : length(l), width(w) {}
    double area() override {
        return length * width;
    }
};


class Cube : public ThreeDShape {
private:
    double side;
public:
    Cube(double s) : side(s) {}

    double volume() override {
        return side * side * side;
    }

    double area() override {
        return 6 * side * side;
    }
};

int main(){
    TwoDShape* square = new Square(4);
    cout << "Area of square: " << square->area() << endl;

    TwoDShape* rectangle = new Rectangle(4, 5);
    cout << "Area of rectangle: " << rectangle->area() << endl;

    ThreeDShape* cube = new Cube(3);
    cout << "Volume of cube: " << cube->volume() << endl;

    return 0;
}