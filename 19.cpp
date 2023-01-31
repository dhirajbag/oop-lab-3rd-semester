/*
Dhiraj Bag, Roll: 001911001033,
BE in IT (2nd Year 1st Semester)
*/

/*Classes and Objects: Rectangle*/

#include<iostream>
#include<cmath>
using namespace std;

class Rectangle{
    int length, breadth;

public:
    Rectangle(int length, int breadth)
        :length(length), breadth(breadth) {}

    int area(){
        return length*breadth;
    }
};
int main(){

    Rectangle r1(1,2), r2(3,4), r3(5,6), r4(7,8);

    cout<<"Area 1: "<<r1.area()<<" sq. Unit"<<endl;
    cout<<"Area 2: "<<r2.area()<<" sq. Unit"<<endl;
    cout<<"Area 3: "<<r3.area()<<" sq. Unit"<<endl;
    cout<<"Area 4: "<<r4.area()<<" sq. Unit"<<endl;

    return 0;
}
