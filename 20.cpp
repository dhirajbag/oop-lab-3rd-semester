/*
Dhiraj Bag, Roll: 001911001033,
BE in IT (2nd Year 1st Semester)
*/

/*Classes and Objects: wireless device*/

#include<iostream>
#include<cmath>
#include<random>
#include<time.h>
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

class Device{
    static int device_count;
private:
    Point loc;
    const int id;
    const int range;

public:
    Device(Point location, int range)
    : loc(location), range(range), id(++device_count) {}

    int get_id(){
        return id;
    }

    int get_range(){
        return range;
    }

    void move_to(Point p){
        loc=p;
    }

    bool is_neighbour(const Device &dev){
        return loc.distance(dev.loc)<=range;
    }


};
int Device::device_count;

int main(){

    srand(time(0));

    vector< Device> devices;

    for(int i=0; i<10; i++){
        devices.push_back(Device(Point(rand()%10, rand()%10), rand()%6+1));
    }

    for(int i=0; i<10; i++){
        cout<<"Neighbours of Device: "<<devices[i].get_id()<<" are devices : ";

        bool flag=1;
        for(int j=0; j<10; j++){
            if(j==i) continue;

            if(devices[i].is_neighbour(devices[j])){
                flag=0;
                cout<<devices[j].get_id()<<" ";
            }
        }
        if(flag) cout<<"<empty>";

        cout<<"\n";
    }

    for(int i=0; i<10; i++){
        devices[i].move_to(Point(rand()%10, rand()%10));
    }

    cout<<"\n\nAfter moving all the devices to new (random) location:"<<endl;
    for(int i=0; i<10; i++){
        cout<<"Neighbours of Device: "<<devices[i].get_id()<<" are devices : ";

        bool flag=1;
        for(int j=0; j<10; j++){
            if(j==i) continue;

            if(devices[i].is_neighbour(devices[j])){
                flag=0;
                cout<<devices[j].get_id()<<" ";
            }
        }
        if(flag) cout<<"<empty>";

        cout<<"\n";
    }

    return 0;
}
