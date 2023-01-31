/*
Dhiraj Bag, Roll: 001911001033,
BE in IT (2nd Year 1st Semester)
*/

/*Operator Overloading: design IntArray for the given main function*/

#include<iostream>
using namespace std;


class IntArray{
    friend ostream& operator<<(ostream&, const IntArray&);
private:
    int size;
    int capacity;
    int *arr;

public:
    IntArray(int size=0, int defaultVal=0 ){
        this->size=size;
        this->capacity=2*size;
        arr = new int[capacity];
        for(int i=0; i<size; i++){
            arr[i]=defaultVal;
        }
    }
    ~IntArray(){
        delete [] arr;
    }

    void push_back(int val){
        if(size==capacity){//double the capacity
            IntArray tmp(*this);
            delete [] arr;
            capacity*=2;
            arr = new int[capacity];
            for(int i=0; i<size; i++){
                arr[i]=tmp.arr[i];
            }
        }
        arr[size++]=val;
    }
    int pop_back(){
        try{
            if(size==0)
                throw("Error: IntArray is already empty!");

            return arr[--size];
        }
        catch(char *ex){
            cout<<ex<<endl;
        }
    }

    const int& operator[](int i)  const{//accessor, when used on rhs of an expression
        //could have instead returned by value also
        return arr[i];
    }
    int& operator[](int i){//mutator, when used on lhs of an expression
        //Non constant reference must be returned
        return arr[i];
    }
};

ostream& operator<<(ostream &out, const IntArray &arr){
    out<<"IntArray: [ ";
    for(int i=0; i<arr.size; i++){
        out<<arr[i]<<" ";
    }
    out<<"] "<<endl;

    return out;
}

int main(){
    IntArray i(10);

    for(int k=0; k<10; k++)
        i[k]=k;

    cout<<i;
    return 0;

    return 0;
}
