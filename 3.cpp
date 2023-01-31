/*
Dhiraj Bag, Roll: 001911001033,
BE in IT (2nd Year 1st Semester)
*/

#include<iostream>
using namespace std;

/* C++ Style Input/Output: Factorial Table */

int main(){
    int n=6;
    int fact=1;
    for(int i=1; i<=n; i++){
        fact=fact*i;
        cout<<i<<"! = "<<fact<<endl;
    }

    return 0;
}
