/*
Dhiraj Bag, Roll: 001911001033,
BE in IT (2nd Year 1st Semester)
*/

/*Inheritance: class Employee, Manager and Clerk*/

#include<iostream>
using namespace std;

class Employee{
protected:
    const char *name;
    int salary;

public:

    Employee(const char *name, int salary)
    :name(name), salary(salary) {}

    const char* getName(){
        return name;
    }
    int getSalary(){
        return salary;
    }
    void setName(const char *name){
        this->name=name;
    }
    void setSalary(int salary){
        this->salary=salary;
    }

    virtual void printDetails(){
        cout<<"Employee: "<<"\n\tName: "\
        <<name<<"\n\tSalary: "<<salary<<endl;
    }

};

class Manager : public Employee{

    const char *type;

public:
    Manager(const char* name, int salary, const char *type)
    : Employee(name, salary), type(type) {}

    const char* getType(){
        return type;
    }
    void setType(const char *type){
        this->type=type;
    }

    void printDetails(){
        cout<<"Manager: "<<"\n\tName: "\
        <<name<<"\n\tSalary: "<<salary\
        <<"\n\tType: "<<type<<endl;
    }
};

class Clerk : public Employee{

    int allowance;

public:
    Clerk(const char* name, int salary, int allowance)
    : Employee(name, salary), allowance(allowance) {}

    int getAllowance(){
        return allowance;
    }
    void setAllowance(int allowance){
        this->allowance=allowance;
    }

    void printDetails(){
        cout<<"Clerk: "<<"\n\tName: "\
        <<name<<"\n\tSalary: "<<salary\
        <<"\n\tAllowance: "<<allowance<<endl;
    }
};


int main(){

    Manager m1("ABC XYZ", 50000, "Type1");
    m1.printDetails();

    Clerk c1("DEF GHY", 20000, 5000);
    c1.printDetails();

    Employee* arr[6];

    arr[0] = new Employee("E1", 30000);
    arr[1] = new Employee("E2", 25000);
    arr[2] = new Manager("M1", 60000, "Type3");
    arr[3] = new Manager("M2", 55000, "Type2");
    arr[4] = new Clerk("C1", 20000, 5000);
    arr[5] = new Clerk("C2", 23000, 4000);

    for(int i=0; i<6; i++){
        arr[i]->printDetails();
        delete arr[i];
    }

    return 0;

}
