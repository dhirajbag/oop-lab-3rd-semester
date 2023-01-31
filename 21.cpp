/*
Dhiraj Bag, Roll: 001911001033,
BE in IT (2nd Year 1st Semester)
*/

/*Classes and Objects: class Vector of 1D array*/
/*
* implemented:
* zero parameter constructor
* default value constructor
* copy constructor
* destructor
* operator +, -
* operator ==, >, <
* operator [] both accessor and mutator versions
* a print function (member)
* created vector and checked whether works properly
*/

#include<iostream>
using namespace std;

template <class T>
class Vector{
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
        catch (const char *ex){
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
        catch (const char *ex){
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
        catch(const char *ex){
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
        catch(const char *ex){
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

int main(){

    Vector<int> vec1(10, 2); //constructing with default value 2
    cout<<"Vector1 "; vec1.print();

    Vector<int> vec2(10,3);
    vec2[4]=5; //Mutator [] invoked
    cout<<"Vector2 "; vec2.print();

    Vector<int> vec3=vec1+vec2;
    cout<<"Vector3 "; vec3.print();

    if(vec1==vec2)
        cout<<"Vector1 is equal to Vector2"<<endl;
    else
        cout<<"Vector1 is not equal to Vector2"<<endl;

    if(vec1<vec2)
        cout<<"Vector1 is less than Vector2"<<endl;
    else
        cout<<"Vector1 is not less than Vector2"<<endl;

    if(vec1>vec2)
        cout<<"Vector1 is greater than Vector2"<<endl;
    else
        cout<<"Vector1 is not greater than Vector2"<<endl;


    return 0;
}
