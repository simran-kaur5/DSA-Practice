#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> stockSpan(vector<int>vec){
    int n = vec.size();
    stack<int>s;
    s.push(0);
    vector<int>ans(n);
    ans[0] = 1;

    for(int i =1;i<n;i++){

        while(s.size() >0 && vec[i] >= vec[s.top()]){
            s.pop();
        }
        if(s.size()==0){
            ans[i] = i+1;
            s.push(i);
        }else{
        ans[i] = i- s.top();
        s.push(i);
        }
    }
    return ans;
}
int main(){

    vector<int> vec = {100,80,60,70,60,85,100};

    vector<int>ans = stockSpan(vec);
    for(int num:ans){
        cout<<num<<" ";
    }
    return 0;
}