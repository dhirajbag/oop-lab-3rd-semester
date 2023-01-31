/*
Dhiraj Bag, Roll: 001911001033,
BE in IT (2nd Year 1st Semester)
*/

/*Operator Overloading: design class Integer for the given main function*/

#include<iostream>
using namespace std;
class Integer{
    friend ostream& operator<<(ostream&, const Integer&);
private:
    int val;
public:
    Integer(int x=0)
    :val(x) {}

    Integer operator+ (const Integer &rhs){
        return Integer(val+rhs.val);
    }
    Integer operator++(int){
        Integer tmp(val);
        val++;
        return tmp;
    }
    operator int(){
        return val;
    }
};

ostream& operator<<(ostream &out, const Integer &obj){
    out<<obj.val;
    return out;
}

int main(){
    Integer a=4, b=a, c;
    c=a+b++;
    int i=a;
    cout<<a<<b<<c;
    return 0;
}
