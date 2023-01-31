/*
Dhiraj Bag, Roll: 001911001033,
BE in IT (2nd Year 1st Semester)
*/

/*Function Overloading: max()*/

#include<iostream>
using namespace std;


 int max(int a, int b, int c){

     if(a>=b&&a>=c) return a;

     if(b>=c) return b;

     return c;
 }

 int max(int arr[], int n){
     int res=arr[0];
     for(int i=1; i<n; i++){
        if(arr[i]>res) res=arr[i];
     }
     return res;
 }

int main(){

    int n=5;
    int arr[n] = {5, 2, 30, 1, -4};
    int a=3, b=6, c=-4;

    cout<<"Max in array: "<<max(arr,n)<<endl;
    cout<<"Max among a,b,c : "<<max(a,b,c)<<endl;
    return 0;
}
