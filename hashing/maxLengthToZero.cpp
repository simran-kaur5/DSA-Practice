#include<iostream>
#include<algorithm>
#include<climits>
#include<vector>
#include<unordered_map>
using namespace std;
int maxLength(vector<int>&vec){
    unordered_map<int,int>m;
    int sum=0;
    int length = 0;
    for(int i =0;i<vec.size();i++){
        sum+=vec[i];
        if (sum == 0) {
            length = max(length, i + 1);  // handle prefix sum = 0
        }
        if(m.find(sum)==m.end()){
            m[sum]=i;
        }else{
            length = max(length,i-m[sum]);
        }
    }

    return length;
}
int main(){

    vector<int>vec = {15,-2,2,-8,1,7,10};
    cout<<"Max Length of sum equal to 0 is: "<<maxLength(vec);
    return 0;
}
