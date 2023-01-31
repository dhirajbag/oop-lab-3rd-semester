#include<iostream>
#include<random>
#include<time.h>
using namespace std;

typedef struct Subject{
    const char *name;
    int totalMarks;
    int weight;

    Subject(const char* name, int marks=100, int weight=1)
    : name(name), totalMarks(marks), weight(weight)  {}
} Subjects;

class gradeCard{
    const char *name;
    const char *dept;
    int sem;
    int roll;
    int numPapers;
    double cgpa;
    Subject *papers;
    int *marks;
    int totalMarks;


public:
    gradeCard(int roll, int sem, const char *name, const char *dept)
    : roll(roll), sem(sem), name(name), dept(dept) {
        numPapers=cgpa=-1;
    }

    void setSubjects(int numSubs, Subject subs[], int subjectMarks[]){
        numPapers=numSubs;
        papers=(Subject*) malloc(numSubs*sizeof(Subject));
        marks=(int*) malloc(numSubs*sizeof(int));
        totalMarks=0;
        for(int i=0; i<numSubs; i++){
            papers[i]=subs[i];
            marks[i]=subjectMarks[i];
            totalMarks+=marks[i];
        }
        double percentage=(double)totalMarks/numPapers; //100 marks each paper
        if(percentage>95.0) cgpa=10.0;
        else cgpa=percentage/9.5;
    }

    double getCgpa(){
        return cgpa;
    }
    int getRoll(){
        return roll;
    }
    const char * getName(){
        return name;
    }
};

void generateRandomMarks(int num, int marks[]){
    for(int i=0; i<num; i++)
        marks[i]=1+rand()%100;
}


int main(){
    srand(time(0));

    Subject subs[5]={
        {
            "Object Oriented Programming"
        },
        {
            "Data Structures and Algorithms"
        },
        {
            "Database Management System"
        },
        {
            "Computer Organization and Architecture"
        },
        {
            "Maths for IT -1 "
        }
    };

    int marks[5];
    gradeCard* ptrs[100];
    double bestCgpa=-1;
    int bestIndex=-1;
    for(int i=0; i<100; i++){
            ptrs[i]=new gradeCard(i+1, 3, "def_name", "Information Technology");
            generateRandomMarks(5, marks);
            ptrs[i]->setSubjects(5, subs, marks);
            if(ptrs[i]->getCgpa() > bestCgpa){
                bestCgpa=ptrs[i]->getCgpa();
                bestIndex=i;
            }
    }

    cout<<"Best CGPA: "<<bestCgpa\
    <<"\nRoll: "<<ptrs[bestIndex]->getRoll()\
    <<"\nName: "<<ptrs[bestIndex]->getName()<<endl;



    return 0;
}
