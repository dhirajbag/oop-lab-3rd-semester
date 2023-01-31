/*
Dhiraj Bag, Roll: 001911001033,
BE in IT (2nd Year 1st Semester)
*/

/*Operator Overloading: class Quadratic */
#include<iostream>
#include<cmath>
using namespace std;

/*Will use complex class to represent complex roots of a Quadratic*/
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
    Complex sum(Complex c2){
        return Complex(real+c2.real, img+c2.img);
    }
};

/*Quadratic function: ax^2 + bx + c is implemented*/
class Quadratic{
    friend ostream& operator<<(ostream &, const Quadratic&);
    friend istream& operator>>(istream &, Quadratic &);
private:
    double a,b,c;
public:
    Quadratic(){
        a=b=c=0;
    }
    Quadratic(double a, double b, double c)
    : a(a), b(b), c(c) {}

    Quadratic operator+ (const Quadratic &q2){
        return Quadratic(a+q2.a, b+q2.b, c+q2.c);
    }

    double valueAt(double x){
        return (c + b*x + a*x*x);
    }

    void rootsAtZero(){
        if(b==0.0 && a==0.0){
            cout<<"Note: polynomial has no term of x or x^2\n";
            cout<<"Cannot find root.";
            return;
        }

        if(a==0.0){
            cout<<"Note: polynomial is linear!"<<endl;
            double root=-c/b;
            cout<<"Only root is: "<<root<<endl;
            return;
        }

        double Discri=b*b - 4*a*c;
        if(Discri<0){
            cout<<"Note: Roots are complex."<<endl;
            Complex c1(-b/(2*a), sqrt(-Discri)/(2*a));
            Complex c2(-b/(2*a), -sqrt(-Discri)/(2*a));
            cout<<"Root1: "; c1.disp();
            cout<<"Root2: "; c2.disp();
            return;
        }

        cout<<"Note: Roots are real."<<endl;
        double root1=(-b+sqrt(Discri))/(2*a);
        double root2=(-b-sqrt(Discri))/(2*a);
        cout<<"Root1: "<<root1<<endl;
        cout<<"Root2: "<<root2<<endl;
    }

};


ostream& operator<<(ostream &out, const Quadratic &q){
    out<<"("<<q.a<<")x^2 + ("<<q.b<<")x + "<<q.c<<endl;
    return out;
}

istream& operator>>(istream &in, Quadratic &q){
    in>>q.a>>q.b>>q.c;
    return in;
}

int main(){
    cout<<"The Quadratic ax^2 + bx + c :\n\n"<<endl;

    Quadratic q1;
    cout<<"Enter 1st Quadratic(format: a b c): ";
    cin>>q1;

    Quadratic q2;
    cout<<"Enter 2nd Quadratic(format: a b c) : ";
    cin>>q2;

    Quadratic q3=q1+q2;
    cout<<"Sum_quadratic(ie, 1st + 2nd): ";
    cout<<q3;

    cout<<"Root of sum_quadratic:\n";
    q3.rootsAtZero();

    cout<<"Enter value of x to find value of sum_quadratic(x): ";\
    double x;
    cin>>x;
    cout<<"sum_quadratic(x) = "<<q3.valueAt(x)<<endl;

    return 0;

}
