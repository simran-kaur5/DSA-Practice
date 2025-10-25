#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(pair<int,int>p1 , pair<int,int>p2){
    return p1.second < p2.second;
}

int maxLength(vector<pair<int,int>>p){
    int currEnd = p[0].second;

    int chain = 0;

    sort(p.begin(),p.end(),compare);

    for(int i =1;i<p.size();i++){
        if(currEnd<=p[i].first){
            chain++;
        }
    }

    return chain;
}
int main(){

    int n =5;
    vector<pair<int,int>>p(n,make_pair(0,0));

    p[0] = make_pair(5,24);
    p[1]= make_pair(39,60);
    p[2] = make_pair(5,28);
    p[3] = make_pair(27,40);
    p[4] = make_pair(50,90);

    cout<<"Chain formed is: "<<maxLength(p);


    return 0;
}