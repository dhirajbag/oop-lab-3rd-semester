/*
Dhiraj Bag, Roll: 001911001033,
BE in IT (2nd Year 1st Semester)
*/

#include<iostream>
using namespace std;

/*Flexible Variable Declaration: Celcius to Fahrenheit coversion table using for loop*/

/*
* 100 degree difference in C = 180 degree difference in F
* 1 degree difference in C = 1.8 degree difference in F
* And 0 degree C = 32 degree F
*/

int main(){

    int celcius=0;
    float fahrenheit=32.0;
    const char degree=248; //The degree symbol
    for(int i=1; i<=101; i++){
        cout<<celcius<<degree<<" C = "<<fahrenheit<<degree<<" F"<<endl;
        celcius++;
        fahrenheit+=1.8;
    }

    return 0;
}
