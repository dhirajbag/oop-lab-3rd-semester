/*
Dhiraj Bag, Roll: 001911001033,
BE in IT (2nd Year 1st Semester)
*/

/*Inheritance: Empty class declaration of given hierarchy*/

#include<iostream>
using namespace std;

class A{

};

class B{

};

class C{

};


class D : public A, public B{

};

class E : public B, public C{

};

class F : public D, public E{

};

int main(){
    return 0;
}
