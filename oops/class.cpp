#include <iostream>
#include <string>
using namespace std;

class Student{ // blue print
    // properties
    string name; // this is default private
    // public:without this we cant modify or access these properties in main function 
    float cgpa;
    public:    //accisible to everyone
        int fees;
    protected:
        string phoneNumber;
    // Methods
    public:
    void getPercentage(){
        cout << (cgpa * 10) << "% \n";//there method have access to properties to change them or alter get data from them
    }

    //setters
    void setName(string nameVal){
        name=nameVal;

    }
    void setCgpa(float cgpaVal ){
        cgpa = cgpaVal;
    }

    //getters
    string getName(){
        return name;

    }
    float getCgpa( ){
        return cgpa;
    }
    
};

class User{
    int id;
    string username;
    string password;
    string bio;

    void deactivate(){
        cout<<" deleting account\n";
    }
    void editBio(string newBio){
        bio = newBio;
    }
};
int main(){
    // after declaring the classs memory get allocated
    Student s1; // object of Student class
    // s1.name = "gowdru"; as this is private by default we cant access this in main
    s1.fees =10;
    cout<<endl;
    s1.setName("gowdru");
    s1.setCgpa(10);

    cout<<s1.getName()<<"\n";
    cout<<s1.getCgpa()<<"\n"; 
    cout<<endl;
    cout << sizeof(s1);
    return 0; 
}