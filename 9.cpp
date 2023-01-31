/*
Dhiraj Bag, Roll: 001911001033,
BE in IT (2nd Year 1st Semester)
*/


#include<iostream>
using namespace std;

/*Reference: swap() strings with and without reference */


/* void Swap(const char* str1, const char* str2){ //This function cannot swap the actual arguments
    const char *tmp=str1;
    str1=str2;
    str2=tmp;
} */

void Swap(const char* &str1, const char* &str2){ //This function swaps the actual arguments
    const char *tmp=str1;
    str1=str2;
    str2=tmp;
}

int main(){
    const char *str1="Java";
    /*Null character '\0' is always automatically added
    * at the end of a string literal(ie const char *).
    * No need to worry about it. */
    const char *str2="C++";

    cout<<"Before Swap: Str1="<<str1<<"; Str2="<<str2<<endl;
    Swap(str1, str2);
    cout<<"After Swap: Str1="<<str1<<"; Str2="<<str2<<endl;

    return 0;
}
