/*
Dhiraj Bag, Roll: 001911001033,
BE in IT (2nd Year 1st Semester)
*/

/*Exception Handling: Division by zero */

#include<iostream>
using namespace std;

int main(){
    int a,b;
    cout<<"Division:\nEnter first number: ";
    cin>>a;
    cout<<"Enter second number: ";
    cin>>b;

    try{
        if(b==0)
            throw("Error: Division by zero!");
        double res=(double)a/b;
        cout<<a<<" / "<<b<<" = "<<res<<endl;
    }
    catch(const char *ex){
        cout<<ex<<endl;
    }

    return 0;
}
