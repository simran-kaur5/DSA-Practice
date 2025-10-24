#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void maxActivities(vector<pair<int,int>>p){
    int acitiviy = 1;
    int currEnd = p[0].second;

    for(int i =1;i<p.size();i++){
        if(currEnd<=p[i].first){
            acitiviy++;
            currEnd = p[i].second;
        }
    }
    cout<<"Number of Activites: "<<acitiviy<<endl;
}

bool compare(pair<int,int>p1,pair<int,int>p2){
    return p1.second < p2.second; //sort in basis of second parameter which is end
}
int main(){

    vector<int>start = {0,1,3};
    vector<int>end = {9,2,4};

    vector<pair<int,int>>act(start.size(),make_pair(0,0));


    for(int i =0;i<start.size();i++){
        act[i] = make_pair(start[i] , end[i]); //make_pair is inbuilt in pairs which make pair of two numbers
    }
    sort(act.begin(),act.end(),compare);   

    maxActivities(act);


    return 0;
}