#include<iostream>
#include<stack>
#include<vector>
using namespace std;
void nextG(vector<int>vec){
    int n = vec.size();
    vector<int>ans(n);
    stack<int>s;
    s.push(vec[n-1]);
    ans[n-1] = -1;

    for(int i =n-2;i>=0;i--){    //TC-> O(n)
        while(!s.empty() && s.top() < vec[i]){
            s.pop();
        }

        if(s.empty()){
            ans[i] =-1;
        }else{
            ans[i] = s.top();
        }
        s.push(vec[i]);
    }

    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
}
int main(){

    vector<int> vec = {6,8,0,1,3};
    nextG(vec);

    return 0;
}