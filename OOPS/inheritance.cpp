#include<iostream>
using namespace std;
class Person{
    public:
    string name;
    int age;

};

class Student:public Person{
    public:
    string studentId;

    Student(string n , int a , string s){
        name = n;
        age = a;
        studentId = s;
    }
    void display(){
        cout<<"Name: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
        cout<<"Student Id: "<<studentId<<endl;
    }
};
int main(){
    Student s1("Nobita" , 12 , "XXX");
    s1.display();
    return 0;
}