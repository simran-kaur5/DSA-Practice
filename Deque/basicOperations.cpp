#include<iostream>
#include<deque>
using namespace std;
int main(){

    deque<int>d;
    d.push_front(1);
    d.push_front(2);
    d.push_back(3);
    d.push_back(4);

    d.pop_front();
    d.pop_back();
    cout<<d.front()<<endl; //1
    cout<<d.back()<<endl; //3

    return 0;
}