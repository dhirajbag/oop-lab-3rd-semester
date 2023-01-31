/*
Dhiraj Bag, Roll: 001911001033,
BE in IT (2nd Year 1st Semester)
*/

/*Templates: max()*/

#include<iostream>
using namespace std;

template <class T> // Less than operator < must be defined for T
T Max(T c1, T c2){
    return c1<c2 ? c2:c1;
}

template<>
char* Max<char*>(char* str1, char* str2){
    int i=0;
    while(str1[i]!='\0' && str2[i]!='\0'){
        if(str1[i]<str2[i])
            return str2;
        else if(str1[i]>str2[i])
            return str1;

        i++;
    }

    if(str2[i]!='\0')
        return str2;
    else return str1;

}

class Complex{
    friend ostream& operator<<(ostream&, const Complex&);
private:
    double real, img;

public:
    Complex(double a=0, double b=0)
    :real(a), img(b) {}

    bool operator<(Complex c2){/*Compares the modulus value*/
        double d1=real*real + img*img;
        double d2=c2.real*c2.real + c2.img*c2.img;

        return (d1<d2);
    }
};

ostream& operator<<(ostream &out, const Complex &c){
    out<<"Complex: "<<c.real<<" + i("<<c.img<<")";
    return out;
}

int main(){

    int a1=6, a2=7;
    cout<<Max(a1,a2)<<endl;

    Complex c1(1,1), c2(-3,-3);
    cout<<Max(c1, c2)<<endl;

    char str1[20]="Java";
    char str2[20]="C++";
    cout<< Max<char*>(str1, str2) <<endl;
    return 0;
}
