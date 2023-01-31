/*
Dhiraj Bag, Roll: 001911001033,
BE in IT (2nd Year 1st Semester)
*/

/*Default values for function parameters*/

#include<iostream>
using namespace std;


int add(int a, int b=0, int c=0){
     return (a+b+c);
}

int main(){

    cout<<"add(10,20,30) => "<<add(10,20,30)<<endl;
    cout<<"add(10,20) => "<<add(10,20)<<endl;
    cout<<"add(10) => "<<add(10)<<endl;

    return 0;
}
