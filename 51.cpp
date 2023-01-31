/*
Dhiraj Bag, Roll: 001911001033,
BE in IT (2nd Year 1st Semester)
*/

/*Templates: Stack()*/

#include<iostream>
using namespace std;

/*Declaring template class Stack - Required for declaration of the next function*/
template<class T>
class Stack;

/*Declaring template operator function operator<< () - Required for its friend declaration
 in template class Stack */
template<class T>
ostream& operator<<(ostream &out,  const  Stack<T> &stk);

template<class T>
class Stack{
friend ostream& operator<< <T>(ostream&, const Stack<T>&);
    T *buffer;
    int top;
    int size;

public:
    Stack(int size){
        this->size=size;
        buffer=new T[size];
        top=-1;
    }
    ~Stack(){
        delete [] buffer;
    }
    void push(T val){
        try{
            if(size==top+1)
                throw("Error: Stack Overflow!");
            buffer[++top]=val;
        }
        catch(const char *ex){
            cout<<ex<<endl;
        }
    }
    T pop(){
        try{
            if(top==-1)
                throw("Error: Stack Underflow!");

            return buffer[top--];
        }
        catch(const char *ex){
            cout<<ex<<endl;
        }
    }

    bool isEmpty(){
        return top==-1;
    }
};
template<class T>
ostream& operator<<(ostream &out,  const  Stack<T> &stk){
    if(stk.top==-1){
        out<<"<Empty>"<<endl;
        return out;
    }

    int i=stk.top;
    out<<"Top --> "<<stk.buffer[i--]<<endl;;
    while(i>=0){
        out<<"        "<<stk.buffer[i--]<<endl;
    }

    return out;
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
    Stack<int> int_stk(10);
    Stack<Complex> complex_stk(10);

    for(int i=0; i<10; i++){
        int_stk.push(i);
        complex_stk.push(Complex(2*i, 3*i));
    }

    int_stk.pop();
    int_stk.pop();
    complex_stk.pop();

    cout<<int_stk<<endl;
    puts("\n");

    cout<<complex_stk<<endl;

    return 0;
}
