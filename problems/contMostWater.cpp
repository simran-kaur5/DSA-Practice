#include <iostream>
#include <algorithm>
#include <climits> // for INT_MIN
#include <vector>
using namespace std;
int maxArea(vector<int>& height) {
        int n = height.size();
        int area = INT_MIN;
        int st =0 , end =n-1;

        while(end>st){
            int waterTrap = ((end-st)*min(height[end] , height[st]));   // update water trap with each iteration
            area = max(area , waterTrap);   //store maximum value of area
            if(height[end] < height[st]){   // decrease smaller bcz we want bigger one
                end--;
            }else{
                st++;
            }
        }
        return area;
}
int main(){
    vector<int>nums = {1,8,6,2,5,4,8,3,7};
    int Area = maxArea(nums);
    cout<<"Most Area trapped by Water: "<<Area<<endl;
}