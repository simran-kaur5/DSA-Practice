#include <iostream>
#include <vector>
using namespace std;
vector<int> findErrorNums(vector<int>& nums , int n) {   // problem number 645 on leetcode 
    vector<bool>isTrue(n+1, false);   // vector size -> n+1 because i to n numbers are in nums 
    vector<int>ans;
        for(int i =0;i<n;i++){
            if(isTrue[nums[i]]){
                ans.push_back(nums[i]);
                continue;
            }
            isTrue[nums[i]] = true;
        }

        for(int i =1;i<n+1;i++){
            if(!isTrue[i]){
                ans.push_back(i);
            }
        }
    return ans;
}
int main(){

    vector<int>vec = {1 , 2 , 2 ,4};
    int n = vec.size();
    vector<int>ans = findErrorNums(vec , n);

    cout<<ans[0] <<" Exits twice in array in place of "<<ans[1]<<endl;
    return 0;
}