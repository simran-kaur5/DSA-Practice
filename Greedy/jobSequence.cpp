#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool compare(pair<int,int>p1,pair<int,int>p2){
    return p1.second < p2.second;
}

int maxProfit(vector<pair<int,int>>jobs){
    int pro = 0;

    sort(jobs.begin(),jobs.end(),compare);

    int nextDeadLine = 1;

    for(int i = jobs.size()-1;i>=0;i--){
        if(nextDeadLine<=jobs[i].first){
            pro+=jobs[i].second;
            nextDeadLine++;  
        }
    }
    return pro;
}
int main(){

    int n =4;
    vector<pair<int,int>>jobs(n,make_pair(0,0));
    jobs[0] = make_pair(4,20);
    jobs[1] = make_pair(1,10);
    jobs[2] = make_pair(1,40);
    jobs[3] = make_pair(1,30);

    cout<<"Maximum Profit we get: " <<maxProfit(jobs);
    return 0;
}