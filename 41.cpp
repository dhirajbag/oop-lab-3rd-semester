/*
Dhiraj Bag, Roll: 001911001033,
BE in IT (2nd Year 1st Semester)
*/

/*Inheritance: class Person and class Student*/

#include<iostream>
using namespace std;

class Person{
protected:
    char *name;
    int age, height;

public:
    Person(char *name)
    :name(name) {}

    Person(char *name, int age)
    :name(name), age(age) {}

    Person(char *name, int age, int height)
    :name(name), age(age), height(height) {}

    char* getName(){
        return name;
    }
    int getAge(){
        return age;
    }
    int getHeight(){
        return height;
    }

    void setName(char *name){
        this->name=name;
    }
    void setAge(int age){
        this->age=age;
    }
    void setHeight(int height){
        this->height=height;
    }

    virtual void printDetails(){
        cout<<"Person: "<<"\n\tName: "\
        <<name<<"\n\tAge: "<<age\
        <<"\n\tHeight: "<<height<<endl;
    }

};


class Student : public Person{
private:
    int roll, yearAdmitted;

public:
    Student(int roll, char *name,  int year, int age=18, int height=5)
    :Person(name, age, height), roll(roll), yearAdmitted(year) {}


    int getRoll(){
        return roll;
    }
    int getYear(){
        return yearAdmitted;
    }
    void setRoll(int roll){
        this->roll=roll;
    }
    void setYear(int year){
        this->yearAdmitted=year;
    }
    void printDetails(){/*Overriding*/
        cout<<"Student: "
        <<"\n\tYear of Admission: "<<yearAdmitted\
        <<"\n\tRoll: "<<roll<<"\n\tName: "\
        <<name<<"\n\tAge: "<<age\
        <<"\n\tHeight: "<<height<<endl;
    }

};

int main(){

    Person p1("ABC XYZ", 20, 6);
    p1.printDetails();

    Student s1(33, "Dhiraj Bag", 2019, 20, 6);
    s1.printDetails();

    Person* arr[4];
    arr[0]=new Person("DEF GHI", 21, 5);
    arr[1]=new Person("JKL MNO", 20, 6);
    arr[2]=new Student(01, "STU ABC", 2019, 20, 6);
    arr[3]=new Student(03, "DEF GHI", 2019, 20, 5);

    cout<<"Printing the objects pointed via the array: "<<endl;
    for(int i=0; i<4; i++){
        arr[i]->printDetails();
    }
     /* For Students, only their Person attributes are printed */
     /* New attributes defined in Student class are truncated */
     /* So only Person class version attributes and member functions are actually called */

     /* adding 'virtual' keyword to printDetails() function in Person class fixes it */

    return 0;

}
