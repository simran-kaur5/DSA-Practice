#include<iostream>
#include<string>
#include<queue>
using namespace std;
class student{
    public:
    int marks;
    string name;

    student(string name,int marks){
        this->name = name;
        this->marks = marks;
    }

    bool operator < (const student &obj) const{    //operator overloading
        return this->marks < obj.marks;
    }
};
int main(){
    priority_queue<student>pq;

    pq.push(student("bhumika",90));
    pq.push(student("anamika",87));
    pq.push(student("varun",65));

    while(!pq.empty()){
        cout<<"Top: "<<pq.top().name<<" have marks: "<<pq.top().marks<<endl;
        pq.pop();
    }

    return 0;
}