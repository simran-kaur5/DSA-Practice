#include <iostream>
using namespace std;
int maxPro(int nums[] , int n ){
    int maxSoFar=1;
    int minSoFar =1;
    int result =0;
    for(int i =0;i<n;i++){
        maxSoFar = max(nums[i], maxSoFar * nums[i]);
        if(nums[i] <0){
            result = min(result, minSoFar);
        }else{
            result = max(result, maxSoFar);
        }
        

    }
    return result;
}
int main(){
    int nums [] = {2,-3,-2,4 , -1 , 8};
    cout<<maxPro(nums , 6);
}