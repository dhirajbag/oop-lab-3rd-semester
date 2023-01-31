/*
Dhiraj Bag, Roll: 001911001033,
BE in IT (2nd Year 1st Semester)
*/

/*Operator Overloading: class Complex */
#include<iostream>
#include<cmath>
using namespace std;

class Complex{
private:
    double real, img;

public:
    Complex(double a=0, double b=0)
    :real(a), img(b) {}

    void setReal(double a){
        real=a;
    }
    void setImg(double b){
        img=b;
    }
    double getReal(){
        return real;
    }
    double getImg(){
        return img;
    }
    void disp(){
        cout<<real<<" + i("<<img<<")\n";
    }
    Complex operator+(const Complex &c2){
        return Complex(real + c2.real, img+c2.img);
    }
    Complex operator-(const Complex &c2){
        return Complex(real - c2.real, img-c2.img);
    }
    Complex operator*(const Complex &c2){
        return Complex(real*c2.real-img*c2.img, real*c2.img + img*c2.real);
    }
    Complex operator/(const Complex &c2){
        try{
            if(c2.real==0 && c2.img==0)
                throw("Error: Cannot divide by zero.");

            Complex res=(*this);
            res = res*Complex(c2.real, -c2.img);
            double divider=c2.real*c2.real + c2.img*c2.img;

            res.real/=divider;
            res.img/=divider;
            return res;
        }
        catch(const char *ex){
            cout<<ex<<endl;
	    return -1;
        }
    }
};

int main(){
    Complex c1(1,2);
    Complex c2(3,4);
    cout<<"Complex c1: "; c1.disp();
    cout<<"Complex c2: "; c2.disp();

    Complex c3=c1+c2, c4=c1-c2, c5=c1*c2, c6=c1/c2;
    cout<<"Complex c1 + c2: "; c3.disp();
    cout<<"Complex c1 - c2: "; c4.disp();
    cout<<"Complex c1 * c2: "; c5.disp();
    cout<<"Complex c1 / c2: "; c6.disp();

    return 0;
}
