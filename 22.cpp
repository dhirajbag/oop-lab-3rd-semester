/*
Dhiraj Bag, Roll: 001911001033,
BE in IT (2nd Year 1st Semester)
*/

/*Classes and Objects: class IntArray for 1D array*/
/*
* Used class definition from 21.cpp
* implemented:
* zero parameter constructor
* default value constructor
* copy constructor
* destructor (already available in Vector class, therefore not required)
* operator +, -
* operator [] both accessor and mutator versions
* reverse()
* sort()
* a print function (member)
* created and checked whether works properly
*/

#include<iostream>
using namespace std;
class IntArray; //declaring for use as  a friend class of Vector<T>

/*########### FROM 21.cpp ########*/
template <class T>
class Vector{
    friend IntArray;
private:
    int size;
    int capacity;
    T *arr;

public:
    Vector(){
        size=0;
        capacity=5;
        arr = new T[capacity];
    }
    Vector(int size, T defaultVal=T() ){
        this->size=size;
        this->capacity=2*size;
        arr = new T[capacity];
        for(int i=0; i<size; i++){
            arr[i]=defaultVal;
        }
    }
    Vector(const Vector &rhs){
        size=rhs.size;
        capacity=rhs.capacity;
        arr= new T[capacity];
        for(int i=0; i<size; i++){
            arr[i]=rhs.arr[i];
        }
    }
    ~Vector(){
        delete [] arr;
    }
    Vector<T> operator+(const Vector<T> &v2){
        try{
            if(size!=v2.size)
                 throw("Error: cannot add. Vectors have different sizes");
            Vector tmp(*this);
            for(int i=0; i<size; i++){
                tmp.arr[i]+=v2.arr[i];
            }

            return tmp;//local tmp returned by value
        }
        catch (char *ex){
            cout<<ex<<endl;
        }
    }
    Vector<T> operator-(const Vector<T> &v2){
        try{
            if(size!=v2.size)
                 throw "Error: cannot subtract. Vectors have different sizes";
            Vector tmp(*this);
            for(int i=0; i<size; i++){
                tmp.arr[i]-=v2.arr[i];
            }

            return tmp;
        }
        catch (char *ex){
            cout<<ex<<endl;
        }
    }
    bool operator==(const Vector<T> &v2){
        if(size!=v2.size)
            return false;

        for(int i=0; i<size; i++){
            if(arr[i]!=v2.arr[i])
                return false;
        }
        return true;
    }
    bool operator<(const Vector<T> &v2){
        try{
            if(size!=v2.size)
                throw("Error: Cannot compare Vectors of different sizes");


            for(int i=0; i<size; i++){
                if(arr[i] >= v2.arr[i])
                    return false;
            }
            return true;
        }
        catch(char *ex){
            cout<<ex<<endl;
        }
    }
    bool operator>(const Vector<T> &v2){
        return (!(*this < v2))&&(!(*this == v2));
    }

    void push_back(T val){
        if(size==capacity){//double the capacity
            Vector tmp(*this);
            delete [] arr;
            capacity*=2;
            arr = new T[capacity];
            for(int i=0; i<size; i++){
                arr[i]=tmp.arr[i];
            }
        }
        arr[size++]=val;
    }
    T pop_back(){
        try{
            if(size==0)
                throw("Error: Vector is already empty!");

            return arr[--size];
        }
        catch(char *ex){
            cout<<ex<<endl;
        }
    }

    void print(){
        cout<<"Vector: [ ";
        for(int i=0; i<size; i++){
            cout<<arr[i]<<" ";
        }
        cout<<"]"<<endl;
    }

    const T& operator[](int i)  const{//accessor, when used on rhs of an expression
        //could have instead returned by value also
        return arr[i];
    }
    T& operator[](int i){//mutator, when useon lhs of an expression
        //Non constant reference must be returned
        return arr[i];
    }
};

/*############# IntArray Class ##########*/

class IntArray{
private:
    Vector<int> vec;

public:
    IntArray()
    : vec(Vector<int> ()) {}
    IntArray(int size, int defaultVal=0)
    : vec(Vector<int>(size, defaultVal)) {}

    IntArray(const IntArray &rhs)
    : vec(Vector<int> (rhs.vec)) {}

    /*No need of destructor:
      Because only memory-allocated object Vector<int> already has a destructor defined above
    */

    int operator[](int i)  const{
        return vec[i];
    }
    int& operator[](int i){
        return vec[i];
    }
    IntArray operator+(const IntArray &A2){
        try{
            if(vec.size!=A2.vec.size)
                throw("Error: Cannot add IntArrays of different sizes!");

            IntArray tmp(*this);
            for(int i=0; i<tmp.vec.size; i++){
                tmp.vec[i]+=A2.vec[i];
            }

            return tmp;
        }
        catch(char *ex){
            cout<<ex<<endl;
        }
    }
    IntArray operator-(const IntArray &A2){
        try{
            if(vec.size!=A2.vec.size)
                throw("Error: Cannot subtract IntArrays of different sizes!");

            IntArray tmp(*this);
            for(int i=0; i<tmp.vec.size; i++){
                tmp.vec[i]-=A2.vec[i];
            }

            return tmp;
        }
        catch(char *ex){
            cout<<ex<<endl;
        }
    }
    void push_back(int val){
        vec.push_back(val);
    }
    int pop_back(){
        return vec.pop_back();
    }
    void reverse(){
        int n=vec.size;
        int mid=n/2;
        for(int i=0; i<mid; i++){
            int tmp=vec[i];
            vec[i]=vec[n-1-i];
            vec[n-1-i]=tmp;
        }
    }

    void sort() {//Performing basic a bubble sort
        int n=vec.size;

        for(int i=0; i<n-1; i++){
            for(int j=0; j<n-i-1; j++){
                if(vec[j]>vec[j+1]){
                    int tmp=vec[j];
                    vec[j] = vec[j+1];
                    vec[j+1]=tmp;
                }
            }
        }
    }

    void print(){
        vec.print();
    }


};


int main(){
    IntArray A1(10, 1);
    cout<<"A1: "; A1.print();

    int arr[10]={4,2,8,1,9,4,6,8,2,7};
    IntArray A2;
    for(int i=0; i<10; i++){
        A2.push_back(arr[i]);
    }
    cout<<"A2: "; A2.print();
    IntArray A3(A2);
    A2.reverse();
    cout<<"A2 reversed: "; A2.print();

    cout<<"A3: "; A3.print();
    A3.sort();
    cout<<"A3 sorted: "; A3.print();

    puts("\n");

    cout<<"Assignment Instruction Execution: "<<endl;
    IntArray B1;
    B1.push_back(1); B1.push_back(2); B1.push_back(3);
    cout<<"First Array: "; B1.print();
    IntArray B2(B1);//Exacat copy created
    cout<<"Second Array: "; B2.print();
    B2.reverse();
    puts("");
    cout<<"After reversing second array: \n";
    cout<<"First Array: "; B1.print();
    cout<<"Second Array: "; B2.print();


    return 0;
}
