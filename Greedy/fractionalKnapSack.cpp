#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(pair<double,int>p1,pair<double,int>p2){
    return p1.first > p2.first;  //sort Decending order we want high ratio at first
}
int fractionalKnap(vector<int>&val , vector<int>&wg,int W){
    vector<pair<double,int>>ratio; //item having heighest ratio shoukd be added first in knapSack because it will give more Quantity with less weight

    for(int i =0;i<val.size();i++){
        double r = val[i]/(double)wg[i];
        ratio.push_back(make_pair(r,i));
    }

    sort(ratio.begin(),ratio.end(),compare);

    double ans =0;
    for(int i =0;i<val.size();i++){
        int idx = ratio[i].second;

        if(wg[idx]<=W){
            ans+=val[idx];
            W-=wg[idx];
        }else{
            ans+=(ratio[i].first*W);
            W=0;
            break;
        }

    }

    cout<<"Max value is: "<<ans<<endl;
    return ans;
}
int main(){
    vector<int>val = {100,60,120};
    vector<int>wg = {20,10,30};

    fractionalKnap(val,wg,50);
    return 0;
}