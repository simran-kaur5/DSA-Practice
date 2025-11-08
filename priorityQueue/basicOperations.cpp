#include<iostream>
#include<vector>
using namespace std;
class Heap{
    vector<int>vec;

    public:

    void push(int val){
        //first push value at last idx
        vec.push_back(val);

        //correct the CBT to make it max Heap

        int childIdx = vec.size()-1;
        int parIdx = (childIdx -1)/2;

        while(parIdx>=0 && vec[childIdx] > vec[parIdx]){
            swap(vec[childIdx],vec[parIdx]);

            childIdx = parIdx;
            parIdx = (childIdx-1)/2;
        }
    }

        void pop(){

        }

        int top(){
            return vec[0];
        }

        bool isEmpty(){
            return vec.size()==0;
        }
};
int main(){
    Heap heap;
    heap.push(10);
    heap.push(34);
    
    cout<<"Top of heap: "<<heap.top()<<endl;

    return 0;
}