#include<iostream>
#include<queue>
#include<vector>
using namespace std;
struct comparePair {

    bool operator ()(pair<string,int>&p1,pair<string,int>&p2){
    return p1.second < p2.second;
}
};
int main(){

    priority_queue<pair<string,int>,vector<pair<string,int>>,comparePair>pq;

    pq.push(make_pair("bhumika",90));
    pq.push(make_pair("anamika",87));
    pq.push(make_pair("varun",65));

    while(!pq.empty()){
        cout<<"Top: "<<pq.top().first<<" have marks: "<<pq.top().second<<endl;
        pq.pop();
    }

    return 0;
}