/*
Dhiraj Bag, Roll: 001911001033,
BE in IT (2nd Year 1st Semester)
*/

/*Operator Overloading: design class Table for the given main function*/

#include<iostream>
using namespace std;

/*Using IntArray class to implement class Table*/
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
    IntArray(const IntArray &rhs){
        cout<<"IntArray copy construct called"<<endl;
        size=rhs.size;
        capacity=rhs.capacity;
        arr= new int[capacity];
        for(int i=0; i<size; i++){
            arr[i]=rhs.arr[i];
        }
    }
    ~IntArray(){
        delete [] arr;
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
    out<<"[ ";
    for(int i=0; i<arr.size; i++){
        out<<arr[i]<<" ";
    }
    out<<"] "<<endl;

    return out;
}

/*###### class Table ########*/

class Table{
    friend istream& operator>> (istream &, Table &);
    friend ostream& operator<< (ostream &, const Table &);
private:
    IntArray *rows;
    int num_rows, num_cols;

public:
    Table(int n, int m)
    :num_rows(n), num_cols(m){
        rows=new IntArray[n];
        for(int i=0; i<n; i++){
            rows[i]= IntArray(m);
        }
    }
    Table(const Table &tbl)
    :num_rows(tbl.num_rows), num_cols(tbl.num_cols){
        cout<<"Table copy const called"<<endl;
        rows=new IntArray[num_rows];
        for(int i=0; i<num_rows; i++){
            rows[i]=tbl[i]; //Will call copy constructor of IntArray class
        }
    }
    ~Table(){
        delete [] rows;
        //IntArray has destructor defined. They will be automatically called
    }
    const IntArray& operator[](int i)  const{//accessor version
        return rows[i];
    }
    IntArray& operator[](int i){//mutator version
        //Non constant reference must be returned
        return rows[i];
    }
    const Table& operator= (const Table &rhs){
        cout<<"Table: Copy assignment called\n";
        delete [] rows;
        num_rows=rhs.num_rows;
        num_cols=rhs.num_cols;

        rows = new IntArray[num_rows];
        for(int i=0; i<num_rows; i++){
            rows[i] = IntArray(rhs[i]);
        }
	return (*this);
    }

};

istream& operator>> (istream &in, Table &tbl){
    for(int i=0; i<tbl.num_rows; i++){
        for(int j=0; j<tbl.num_cols; j++){
            in>>tbl[i][j];
        }
    }
    return in;
}
ostream& operator<< (ostream &out, const Table &tbl){
    out<<"Table: {\n";
    for(int i=0; i<tbl.num_rows; i++){
        out<<tbl[i];
    }
    out<<"}\n";

    return out;
}

int main(){
    Table t(4,5), t1(4,5);
    //Table t(2,2), t1(2,2);

    cin>>t;
    t[0][0]=5;
    int x=t[1][1];
    t1=t; /*Risk of aliasing. Need to define copy assignment
            *operator(1st preference) or copy constructor(if doesn't find copy assignment, it will be used)
            */

    cout<<t<<"\n"<<t1;
    return 0;
}
