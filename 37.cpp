/*
Dhiraj Bag, Roll: 001911001033,
BE in IT (2nd Year 1st Semester)
*/

/*Operator Overloading: design classes for the given main function*/

#include<iostream>
using namespace std;

class Index{
private:
    int data;
public:
    Index(int x)
    : data(x) {}

    Index operator+ (const Index &in){
        return Index(data + in.data);
    }
    int getData() const{
        return data;
    }
    operator int(){
        return data;
    }
};

class Integer{
private:
    int data;
public:
    Integer(int x=0)
    :data(x) {}
    Integer(const Index &in){
        data=in.getData();
    }
};

int main(){
    Index in(4), out(10);
    int x=in;
    int y=in + out;
    in=2;
    Integer i;
    i=in;

    return 0;
}
