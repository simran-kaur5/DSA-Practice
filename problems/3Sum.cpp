#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<vector<int>> threeSum(vector<int>nums){   //TC-> O(n^2)   
    //problem number 15 on leetcode
    int n = nums.size();
    sort(nums.begin() , nums.end());
    vector<vector<int>>ans;
    for(int i =0;i<n-2;i++){
        if(nums[i] == nums[i+1]){
            continue;
        }
        int st = i+1 , end = n-1;

        while(end>st){
            if(nums[i]+nums[st] + nums[end]==0){
                ans.push_back({nums[i] , nums[st] , nums[end]});
                 // Skip duplicates for end
                while( end>st && nums[st] == nums[st+1]){
                    st++;
                }
                // Skip duplicates for end
                while(nums[end] == nums[end-1] && end>st){
                    end--;
                }
                st++;
                end--;
            }else if(nums[i]+nums[st] + nums[end]<0){   //if lesser then 0 then increase starting
                st++;
            }else{   //else decrease end
                end--;
            }
        }
    }
}
int main(){
    vector<int>vec = {-1,0,1,2,-1,-4};
    threeSum(vec);
}