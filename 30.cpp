/*
Dhiraj Bag, Roll: 001911001033,
BE in IT (2nd Year 1st Semester)
*/

/*Operator Overloading: class Point */
#include<iostream>
#include<cmath>
using namespace std;

class Point{
    int x,y;
public:
    Point(int x=0, int y=0)
    :x(x), y(y) {}

    void set(int x, int y){
        this->x=x;
        this->y=y;
    }
    void setx(int x){
        this->x=x;
    }
    void sety(int y){
        this->y=y;
    }

    double operator- (Point p2){ //calculates distance
        return sqrt((x-p2.x)*(x-p2.x) + (y-p2.y)*(y-p2.y));
    }
};

int main(){
    Point p1(1,2);
    Point p2(3,4);
    cout<<"Distance: "<<p1-p2<<endl;
}
