/*
Dhiraj Bag, Roll: 001911001033,
BE in IT (2nd Year 1st Semester)
*/

#include<iostream>
using namespace std;

/*Flexible Variable Declaration: For Loop - loop-variable's Scope*/

int main(){

    for(int i=0; i<5; i++){
        cout<<"Local loop variable i = "<<i<<endl;
    }

    //int var=i; //'Error: i not declared' as expected, Since local loop variable
                // 'i's scope ended with its loop


    return 0;
}
