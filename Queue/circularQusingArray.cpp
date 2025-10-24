#include<iostream>
using namespace std;
class Queue{
    int capacity;
    int currSize;
    int f,r;
    int *arr;
public:
    Queue(int capacity){
        this->capacity = capacity;
        f =0;
        r=-1;
        currSize = 0;
        arr = new int[capacity];
    }

    void push(int val){
        if(currSize==capacity){
            cout<<"Queue is FULL..."<<endl;
            return;
        }
        r = (r+1)%capacity;   //update like this beacuse its circular Queue when r = capcity then r becomes again 0
        arr[r] = val;
        currSize++;
    }

    void pop(){
        if(isEmpty()){
            cout<<"Queue is EMPTY.."<<endl;
            return;
        }
        f = (f+1)%capacity;
        currSize--; 
    }

    int front(){
        if(isEmpty()){
            cout<<"Queue is EMPTY.."<<endl;
            return -1;
        }
        return arr[f];
    }

    bool isEmpty(){
        return currSize==0;
    }

    void rear(){
        cout<<arr[r];
    }
};
int main(){

    Queue q(4);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);  //full queue
    cout<<q.front()<<endl;  //1
    q.pop();  //pop 1
    q.pop();  //pop 2
    q.push(8);  //push 8 on rear end which is now staring or array
    cout<<q.front()<<endl;   //its 3 
    q.rear();  //its 8
    return 0;
}