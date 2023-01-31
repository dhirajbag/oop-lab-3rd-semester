/*
Dhiraj Bag, Roll: 001911001033,
BE in IT (2nd Year 1st Semester)
*/

/*Operator Overloading: complete the class INT*/
#include<iostream>
using namespace std;

class INT{
    int i;
public:
    INT(int a) :i(a){}
    ~INT(){}
    INT& operator++(){
        ++i;
        return (*this);
    }
    INT& operator++(int){
        i++;
        return (*this);
    }
    operator int(){
        return i;
    }
    /*No need for copy assignment or copy constructor -- shallow copy is ok.
     Because there is no risk of alias -- all member variables are primitive
     */
};

int main(){
    int x=3;
    INT y=x;
    y++=++y; /* I think this line in the question should have been ' ++y=y++ ' instead. Because post increment returns a r-value. r-value cannot be placed on the left hand side of assignment
             * However, implementing without any modification to question.
             * Due to which I had to return reference in post increment also.
             * Due to which the post increment actually will work exactly like the pre increment
             */
    x=y;

    return 0;
}
