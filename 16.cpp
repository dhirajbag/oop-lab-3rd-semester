/*
Dhiraj Bag, Roll: 001911001033,
BE in IT (2nd Year 1st Semester)
*/

/*Function Overloading: print() for vector and matrix*/

#include<iostream>
#include<vector>
using namespace std;

void print(vector<int> vec){
    cout<<"Vector: [ ";
    for(int i=0; i<vec.size(); i++){
        cout<<vec[i]<<" ";
    }
    cout<<"]\n"<<endl;
}

void print(vector< vector<int> > matrix){
    cout<<"Matrix:\n";
    for(int i=0; i<matrix.size(); i++){
        for(int j=0; j<matrix[i].size(); j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
}

int main(){

    vector<int> vec = {1,2,3,4,5};

    vector< vector<int>> matrix = {
        {1,2,3,4,5},
        {6,7,8,9,0},
        {3,4,5,6,7},
        {2,3,4,5,6},
        {6,7,8,9,0}
    };

    print(vec);

    print(matrix);

    return 0;
}
