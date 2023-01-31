/*
Dhiraj Bag, Roll: 001911001033,
BE in IT (2nd Year 1st Semester)
*/

/*Inheritance: class shape2D */

#include<iostream>
using namespace std;

class Shape2D{
public:
    virtual double area()=0;
    virtual double perimeter()=0;
};

class Circle : public Shape2D{
private:
    int radius;

public:
    Circle(int radius)
    : radius(radius) {}

    double area(){
        return 3.14159*radius*radius;
    }
    double perimeter(){
        return 2*3.14159*radius;
    }

};

class Rectangle : public Shape2D{
private:
    int length, breadth;

public:
    Rectangle(int a, int b)
    :length(a), breadth(b) {}

    double area(){
        return length*breadth;
    }
    double perimeter(){
        return 2*(length+breadth);
    }

};

int main(){
    Circle c(1);

    Shape2D* arr[5]={new Circle(1), new Circle(2), new Circle(3), new Rectangle(1,2), new Rectangle(3,4)};

    for(int i=0; i<5; i++){
        if(i<3){
            cout<<"Circle:\
            \n\tArea: "<<arr[i]->area()<<"\
            \n\tPerimeter: "<<arr[i]->perimeter()<<endl;
        }
        else {
            cout<<"Rectangle:\
            \n\tArea: "<<arr[i]->area()<<"\
            \n\tPerimeter: "<<arr[i]->perimeter()<<endl;
        }

        delete arr[i];
    }

}

