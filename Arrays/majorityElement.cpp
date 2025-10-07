#include<iostream>
#include<vector>
using namespace std;
int maxFreq(vector<int>nums){    //Boyer–Moore Voting Algorithm
    int count =0;
    int element = 0;
    for(int i =0;i<nums.size();i++){
        if(count==0){
            element = nums[i];
        }
        if(element == nums[i]){
            count++;
        }else{
            count--;
        }
    }
    return element;
}

int check(int freqElement,vector<int>nums){     //to check whether the majority element appears more than n/2 times
    int count =0;
    for(int x:nums){
        if(freqElement == x){
            count++;
        }
    }

    int n = nums.size();

    if(count>n/2){
        return freqElement;
    }else{
        return -1;
    }
}
int main(){
    vector<int>nums = {3,2,3,2,3,4,4,3,4,4,4,4,4};
    int freqElement = maxFreq(nums);
    cout<<check(freqElement,nums);
    return 0;
}