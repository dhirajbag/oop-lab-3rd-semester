/*
Dhiraj Bag, Roll: 001911001033,
BE in IT (2nd Year 1st Semester)
*/

/*Classes & Objects: Notion of constant member functions
* And mutable data members*/
#include<iostream>
using namespace std;

class Test{
private:
    int data1;
    mutable int data2; //mutable data member


private:
    /*void setData1(int val)const{//constant member function
        data1=val;
    }*/ //Erroneous code. Because constant functions cannot modify data



    /*
    * However, if data member is mutable type, then even constant member
    * function can modify it.
    */
    void setData2(int val)const {
        data2=val; //Modifying a mutable data member //OK
    }
};

int main(){
    return 0;
}
