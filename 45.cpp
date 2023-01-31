/*
Dhiraj Bag, Roll: 001911001033,
BE in IT (2nd Year 1st Semester)
*/

/*Inheritance: Virtual Destructor */

#include<iostream>
using namespace std;


class Base{
public:
    Base(){
        cout<<"Base class constructor called.\n";
    }
    virtual ~Base(){
        cout<<"Base class destructor called.\n";
    }
};

class Derived : public Base{
public:
    Derived(){
        cout<<"Derived class constructor called.\n";
    }
    ~Derived(){
        cout<<"Derived class destructor called.\n";
    }
};

int main(){

    Base *basePtr= new Derived;
    delete basePtr;

    /* If we don not make base destructor a virtual destructor,
       Derived class destructor will not be called after the delete
       statement above
    */

    /* Adding virtual keyword at the Base class destructor
       solves the issue
    */

    return 0;
}
