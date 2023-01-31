/*
Dhiraj Bag, Roll: 001911001033,
BE in IT (2nd Year 1st Semester)
*/

/*Classes and Objects: fill the class stack definition*/

#include<iostream>
using namespace std;

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
	    return -1;
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
};

int main(){
    Stack stk(10);
    stk.push(2);
    stk.push(3);
    stk.push(4);
    stk.push(5);
    stk.pop();
    stk.disp();
}
