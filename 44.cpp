/*
Dhiraj Bag, Roll: 001911001033,
BE in IT (2nd Year 1st Semester)
*/

/*Inheritance: class Shape */

#include<iostream>
#include<cmath>
using namespace std;
const double PI=3.14159;

class Shape{
public:
    char dim;
    const char *name;
    virtual double getArea()=0;
    virtual double getVolume()=0;
};

class TwoDShape : public Shape{
private:
    double getVolume() {
        return 0;
    }
public:
    TwoDShape(){
        dim=2;
    }
};
class Circle : public TwoDShape{
private:
    int radius;
public:
    Circle(int r)
    : radius(r) {
        name="Circle";
    }

    double getArea(){
        return PI*radius*radius;
    }
};

class Triangle : public TwoDShape{
    private:
        int a, b, c;

    public:
        Triangle(int a, int b, int c)
        : a(a), b(b), c(c) {
            name="Triangle";
        }

        double getArea(){
            double s=(a+b+c)/2.0;
            return sqrt(s*(s-a)*(s-b)*(s-c));
        }
};

class Ellipse : public TwoDShape{
private:
    int a, b;

public:
    Ellipse(int a, int b)
    : a(a), b(b) {
        name="Ellipse";
    }

    double getArea(){
        return PI*a*b;
    }
};

class ThreeDShape : public Shape{
public:
    ThreeDShape(){
        dim=3;
    }
};

class Sphere : public ThreeDShape{
private:
    int radius;

public:
    Sphere(int r)
    : radius(r) {
        name="Sphere";
    }

    double getArea(){
        return 4.0*PI*radius*radius;
    }
    double getVolume(){
        return 4.0*PI*radius*radius*radius/3.0;
    }
};

class Cube : public ThreeDShape{
private:
    int a;

public:
    Cube(int a)
    : a(a) {
        name="Cube";
    }

    double getArea(){
        return 6*a*a;
    }
    double getVolume(){
        return a*a*a;
    }
};


int main(){

    Shape* arr[5]={ new Circle(2), new Triangle(3,2,4), new Ellipse(3,4), new Sphere(4), new Cube(5)};

    for(int i=0; i<5; i++){
        cout<<arr[i]->name<<":\n";
        cout<<"\tArea: "<<arr[i]->getArea()<<endl;

        if(arr[i]->dim==3)
            cout<<"\tVolume: "<<arr[i]->getVolume()<<endl;

        cout<<endl;

        delete arr[i];
    }



}

