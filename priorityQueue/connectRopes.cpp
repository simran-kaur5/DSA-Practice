#include<iostream>
#include<queue>
#include<vector>
using namespace std;
void connectRopes(vector<int>& ropes){
    int cost =0;
    priority_queue<int,vector<int>,greater<int>> pq(ropes.begin(),ropes.end());

    while(pq.size()>1){
        int min1 = pq.top();
        pq.pop();
        int min2 = pq.top();
        pq.pop();
        int addRope = min1 + min2;
        cost+=addRope;
        pq.push(addRope);
    }

    cout<<"Min cost: "<<cost<<endl;
}
int main(){

    vector<int>ropes = {2,3,4,6};
    connectRopes(ropes);
    return 0;
}