#include <iostream>
using namespace std;
//multiple inheritance

class Teacher{
    public:
        int salary;
        string subject;
};

class Student{
public:
    int rollno;
    float cgpa;
};

class TA : public Teacher,public Student{
    public:
    string name;
};

int main(){
    TA ta1;
    ta1.name = "Rahul";
    ta1.subject = "C++";
    ta1.cgpa = 9.5;

    cout<<ta1.name<<endl;
    cout<<ta1.subject<<endl;
    cout<<ta1.cgpa<<endl;
    return 0;
}