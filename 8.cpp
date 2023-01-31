/*
Dhiraj Bag, Roll: 001911001033,
BE in IT (2nd Year 1st Semester)
*/

/*Reference: swap(int&, int&) */

#include<iostream>
using namespace std;

void swap(int &, int &);

int main(){

    int a=20, b=30;
    cout<<"Before swap, (a,b) = ("<<a<<","<<b<<")"<<endl;

    swap(a,b);
    cout<<"After swap, (a,b) = ("<<a<<","<<b<<")"<<endl;

    return 0;
}

void swap(int &a, int &b){

    a=a+b;
    b=a-b;
    a=a-b;
}
