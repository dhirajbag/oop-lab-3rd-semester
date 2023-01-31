/*
Dhiraj Bag, Roll: 001911001033,
BE in IT (2nd Year 1st Semester)
*/

/*Classes & Objects: class Complex */
#include<iostream>
using namespace std;

class Complex{
private:
    float real, img;

public:
    Complex(float a=0, float b=0)
    :real(a), img(b) {}

    void setReal(float a){
        real=a;
    }
    void setImg(float b){
        img=b;
    }
    float getReal(){
        return real;
    }
    float getImg(){
        return img;
    }
    void disp(){
        cout<<real<<" + i("<<img<<")\n";
    }
    Complex sum(Complex c2){
        return Complex(real+c2.real, img+c2.img);
    }
};

int main(){
    Complex c1, c2, c3;
    c1.setReal(1); c1.setImg(2);
    c2.setReal(3); c2.setImg(4);
    c3.setReal(5); c3.setImg(6);

    Complex c=(c1.sum(c2)).sum(c3);
    cout<<"Complex1: "; c1.disp();
    cout<<"Complex2: "; c2.disp();
    cout<<"Complex3: "; c3.disp();
    cout<<"Complex_Sum: "; c.disp();
    return 0;
}
