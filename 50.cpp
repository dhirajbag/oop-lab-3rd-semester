/*
Dhiraj Bag, Roll: 001911001033,
BE in IT (2nd Year 1st Semester)
*/

/*Templates: swap()*/

#include<iostream>
using namespace std;

/*##### Classes Used ######*/
class Stack{
    int *buffer, top;
    int size;

public:
    Stack(int size){
        this->size=size;
        buffer=new int[size];
        top=-1;
    }
    ~Stack(){
        delete [] buffer;
    }
    void push(int val){
        try{
            if(size==top+1)
                throw("Error: Stack Overflow!");
            buffer[++top]=val;
        }
        catch(const char *ex){
            cout<<ex<<endl;
        }
    }
    int pop(){
        try{
            if(top==-1)
                throw("Error: Stack Underflow!");

            return buffer[top--];
        }
        catch(const char *ex){
            cout<<ex<<endl;
        }
    }
    void disp(){
        if(top==-1){
            cout<<"<Empty>"<<endl;
            return;
        }

        int i=top;
        cout<<"Top --> "<<buffer[i--]<<endl;;
        while(i>=0){
            cout<<"        "<<buffer[i--]<<endl;
        }
    }
    bool isEmpty(){
        return top==-1;
    }
};


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
/*#####################*/

template<class T>
void Swap(T &obj1, T &obj2){
    T tmp=obj1;
    obj1=obj2;
    obj2=tmp;
}
template<>
void Swap<Stack>(Stack &stk1, Stack &stk2){
    Stack tmp(60);

    int size_stack2=0;
    while(!stk1.isEmpty()){
        tmp.push(stk1.pop());
    }
    while(!stk2.isEmpty()){
        tmp.push(stk2.pop());
        size_stack2++;
    }
    while(size_stack2--){
        stk1.push(tmp.pop());
    }
    while(!tmp.isEmpty()){
        stk2.push(tmp.pop());
    }

/*Stack has destructor defined. Will be automatically deleted*/
}


int main(){
    int a1=10, a2=20;
    Complex c1(1,5), c2(10,15);
    Stack stk1(10), stk2(10);
    for(int i=0; i<10; i++)
         stk1.push(i);
    for(int i=10; i<20; i++)
            stk2.push(i);

    cout<<"Before Swap: \n\n";
    cout<<"Int1: "<<a1<<"; Int2: "<<a2<<endl;
    cout<<"Complex1: "<<c1<<"; Complex2: "<<c2<<endl;
    cout<<"Stack1:\n"; stk1.disp();
    cout<<"\nStack2:\n"; stk2.disp();

    Swap(a1,a2);
    Swap(c1,c2);
    Swap<Stack>(stk1, stk2);


    cout<<"\n\n\nAfter Swap: \n\n";
    cout<<"Int1: "<<a1<<"; Int2: "<<a2<<endl;
    cout<<"Complex1: "<<c1<<"; Complex2: "<<c2<<endl;
    cout<<"Stack1:\n"; stk1.disp();
    cout<<"\nStack2:\n"; stk2.disp();

}
