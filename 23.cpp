#include<iostream>
#include<random>
#include<time.h>
using namespace std;
int randomAmt(){
    return 1000 + rand()%99001;
}
class Account{
    static int count;
    static double rateOfInterest;
    const char *name;
    const int accNum;
    double bal;

public:
    Account(double initBal=randomAmt(), const char* name="def_name")
    :accNum(++count), name(name), bal(initBal){
        cout<<"Account Created:\n\
               A/c No.: "<<accNum<<"\n\
               Initial Balance: "<<bal<<endl;
    }

    void withdraw(int amt){
        if(bal-amt <1000){
            cout<<"Cannot withdraw! Minimum balance of Rs 1000.00 must be maintained."<<endl;
            return;
        }
        bal-=amt;
        cout<<"Withdrawn Rs "<<amt<<". Available balance: Rs "<<bal<<endl;
    }

    void deposit(int amt){
        bal+=amt;
        cout<<"A/c "<<accNum<<": Deposited Rs "<<amt<<". Available balance: Rs "<<bal<<endl;
    }

    double getValueOfInterest(){
        return bal*rateOfInterest;
    }

    void depositInterest(){
        double amt=getValueOfInterest();
        deposit(amt);
    }
};
int Account::count=0;
double Account::rateOfInterest=0.08;
int main(){
    srand(time(0));

    Account arr[100];

    double totalInterest=0.0;
    for(int i=0; i<100; i++){
        totalInterest+=arr[i].getValueOfInterest();
        arr[i].depositInterest();
    }

    cout<<"\nTotal Interest (sum over all accounts) for 1 year: "<<totalInterest<<endl;


    return 0;
}
