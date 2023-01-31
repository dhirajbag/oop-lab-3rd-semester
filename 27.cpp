/*
Dhiraj Bag, Roll: 001911001033,
BE in IT (2nd Year 1st Semester)
*/

/*Classes and Objects: fill the class Queue definition*/


#include<iostream>
using namespace std;

class Queue{
private:
    int *data;
    int front, rear;
    int size;

public:
    Queue(int size){
        this->size=size;
        data = new int[size];
        front=rear=-1;
    }
    ~Queue(){
        delete [] data;
    }

    void add(int val){
        if(front==-1){
            front=rear=0;
            data[front]=val;
        }
        else{
            try{
                if((rear+1)%size==front)
                    throw "Error: Queue is full. Item not added.";

                rear=(rear+1)%size;
                data[rear]=val;
            }
            catch(const char *ex){
                cout<<ex<<endl;
            }
        }
    }

    int remove(){
        try{
            if(front==-1)
                throw "Error! Queue is already empty.";

            int val = data[front];

            if(front==rear)
                rear=front=-1;
            else {
                front = (front+1)%size;
            }

            return val;
        }
        catch(const char *ex){
            cout<<ex<<endl;
	    return -1;
        }
    }

    void disp(){
        cout<<"Queue: ";
        if(front==-1){
            cout<<"<Empty>\n";
            return;
        }

        for(int i=front; ; ){
            cout<<data[i]<<" ";
            if(i==rear)
                break;

            i=(i+1)%size;
        }
        cout<<endl;
    }
};

int main(){
    Queue Q(10);
    Q.add(2); Q.add(3); Q.add(4); Q.add(5);
    Q.remove(); Q.remove();
    Q.disp();

    return 0;
}
