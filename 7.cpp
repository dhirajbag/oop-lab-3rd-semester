/*
Dhiraj Bag, Roll: 001911001033,
BE in IT (2nd Year 1st Semester)
*/

/*Constants: factorial(const int)*/

#include<iostream>
using namespace std;

long factorial(const int);

int main(){

    long res=factorial(5);
    cout<<"Factorial of 5 is: "<<res<<endl;

    return 0;
}

long factorial(const int n){

    if(n<0) {
        cout<<"Error: n cannot be negetive."<<endl;
        return 0;
    }

    long fact=1;

    for(int i=2; i<=n; i++){
        fact*=i;
    }

    return fact;
}
