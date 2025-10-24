#include<iostream>
#include<queue>
using namespace std;

void interleave(queue<int>&q){
    int size = q.size();

    queue<int>first;
    for(int i =0;i<size/2;i++){
        first.push(q.front());
        q.pop();
    }

    while(!first.empty()){
        q.push(first.front());
        first.pop();
        q.push(q.front());
        q.pop();
    }

    if(!q.empty() && size%2!=0){
        q.push(q.front());
        q.pop();
    }

    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
}
int main(){

    queue<int>q ;
    for(int i =1;i<10;i++){
        q.push(i);
    }

    interleave(q);
    return 0;
}