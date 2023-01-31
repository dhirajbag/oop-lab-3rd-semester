/*
Dhiraj Bag, Roll: 001911001033,
BE in IT (2nd Year 1st Semester)
*/

/*Inline function: inline add(int, int, int)*/

#include<iostream>
using namespace std;


 inline int add(int a, int b, int c){
     return (a+b+c);
}

int main(){

    int a=10, b=20, c=30;
    int sum = add(a,b,c);

    cout<<"Sum = "<<sum<<endl;

    return 0;
}
