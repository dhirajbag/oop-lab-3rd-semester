/*
Dhiraj Bag, Roll: 001911001033,
BE in IT (2nd Year 1st Semester)
*/

/*Classes and Objects: Point*/

#include<iostream>
#include<cmath>
using namespace std;

class Point{
    int x,y,z;

public:
    Point(int x=0, int y=0, int z=0)
        :x(x), y(y), z(z) {}

    double distance(const Point &p){
        double dist=pow(x-p.x,2)+pow(y-p.y,2)+pow(z-p.z,2);
        dist=sqrt(dist);
        return dist;
    }
};
int main(){

    Point p1(1,2,3), p2(4,5,6);
    cout<<"Distance: "<<p1.distance(p2)<<" Unit"<<endl;

    return 0;
}
