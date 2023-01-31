#include<iostream>
using namespace std;


class HighWay{
    int numLanes;
    static char *statusOfLane; //0=> unoccupied, '+' car going in positive direction, '-' car going in negetive direction

public:
    HighWay(int num=1) :numLanes(num) {
        statusOfLane=(char*)malloc(numLanes*sizeof(char));
        for(int i=0; i<numLanes; i++){
            statusOfLane[i]=0;
        }
    }

    void addVehicle(int laneNumber, char direction){
        try{
            if(laneNumber <=0 || laneNumber >numLanes)
                throw("Error: Invalid Lane Number!");

            if(!(direction=='+' || direction=='-'))
                throw("Error: Invalid direction! Supports '+' or '-' .");

            if(statusOfLane[laneNumber]==0){
                statusOfLane[laneNumber]=direction;
            }
            else if(statusOfLane[laneNumber]!=direction)
                throw("Error! Already there is a car in opposite direction in same lane.");


            cout<<"Done.\n";
        }
        catch(const char* ex){
            cout<<ex<<endl;
        }
        catch(...){}
    }

};
char* HighWay::statusOfLane;

int main(){
    HighWay H(4);

    char op=1;
    while(op){
        cout<<"\nEnter:\n\t '+' To add vechicle in '+' direction."<<\
              "\n\t '-' To add vehicle in '-' direction."<<\
              "\n\t '0' To Exit the program.\n\t: ";

        cin>>op;

        switch(op){
        case '+': {
                int n;
                cout<<"Enter lane number: ";
                cin>>n;
                H.addVehicle(n, '+');
            }
            break;

        case '-':
            {
                int n;
                cout<<"Enter lane number: ";
                cin>>n;
                H.addVehicle(n, '-');
            }
            break;

        case '0':
            return 0;

        default:
            cout<<"Invalid Input"<<endl;
            break;
        }
    }


    return 0;

}
