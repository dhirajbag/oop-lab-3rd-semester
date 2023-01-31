/*
Dhiraj Bag, Roll: 001911001033,
BE in IT (2nd Year 1st Semester)
*/

/*Constants and pointers: Strcpy(const char * const src, char * const dest) */

#include<iostream>
using namespace std;

void Strcpy(const char * const src, char * const dest){
    /*
    * Following the instructions, ie:
    * - src string must not get modified
    * - dest string is allowed to get modified
    * - both the pointers must be constant-poninters
    */

    int i;
    for(i=0; src[i]!='\0'; i++){
        dest[i]=src[i];
    }

    while(dest[i]!='\0'){
        dest[i]='\0';
        i++;
    }
}


int main(){

   char str1[30]="C++";
   char str2[30]="Java";

   Strcpy(str1, str2);
   cout<<str1<<" "<<str2<<endl;


    return 0;
}
