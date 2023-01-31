/*
Dhiraj Bag, Roll: 001911001033,
BE in IT (2nd Year 1st Semester)
*/

/*Inline function: inline vs normal - which one's faster*/

#include<iostream>
#include<bits/stdc++.h>
#include<time.h>
using namespace std;


 inline int add(int a, int b, int c){ //Execution time : 3.765000 sec for 1 Billion calls
     return (a+b+c);
}

/* int add(int a, int b, int c){ //Execution time : 3.860000 sec for 1 Billion calls
     return (a+b+c);
} */

int main(){

    int a=10, b=20, c=30;

    int T=1000000000;

    clock_t start,end;

    start=clock();
    while(T--){
        add(a,b,c);
    }
    end=clock();

    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Execution time : " << fixed<< time_taken << setprecision(5);
    cout << " sec " << endl;

    return 0;
}
