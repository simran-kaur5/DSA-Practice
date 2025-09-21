#include <iostream>
#include <vector>
using namespace std; 

// TC -> O(n)

vector<int> pairSum(vector<int>nums , int n , int target){    // using two pointer Approach
    int st = 0 , end = n-1;
    vector<int>pair;
    while(end>st){
        if(nums[st] + nums[end] == target){
            pair.push_back(st);
            pair.push_back(end);
            return pair;
        }else if(nums[st] + nums[end]  > target){   // if sum is greater than target -> then decrease end
            end--;
        }else{
            st++;    //else ->  sum is less than target -> then increase start
        }
    }
    return {};  // if no pair exists return empty vector
}

int main(){  

    //given -> array is sorted

    //return two indices whose sum is Equal to target 
    vector<int>nums = {2 , 7 , 11 , 13};
    int n = nums.size();
    vector<int>ans = pairSum(nums , n , 9);

    if(ans.size()==0){
        cout<<"No any pair exits";
    }else{
        cout<<"Pairs are: ";
    for(int num:ans){   //print the pair using for each loop
        cout<<num<<" ";
    }
    }
    return 0;
}