#include<iostream>
#include<stack>
#include<climits>
#include<vector>
using namespace std;

void maxArea(vector<int>&vec){
    int n =vec.size();
    stack<int>leftSmall;   //from 0 to n
    stack<int>rightSmall;  //from n to 0

    vector<int>left(n);
    vector<int>right(n);

    left[0]=-1;
    //we will push the first element of the array in stack

    leftSmall.push(0);
    for(int i =1;i<n;i++){

        while(!leftSmall.empty() && vec[leftSmall.top()] >= vec[i]){
            leftSmall.pop();
        }
        if(leftSmall.empty()){
            left[i] =-1;
        }else{
            left[i] = leftSmall.top();
        }
        leftSmall.push(i);
    }


    right[n-1] = n;
    rightSmall.push(n-1);
    for(int i = n-2;i>=0;i--){
        while(!rightSmall.empty() && vec[rightSmall.top()] >= vec[i]){
            rightSmall.pop();
        }
        if(rightSmall.empty()){
            right[i] = n;
        }else{
            right[i] = rightSmall.top();
        }
        rightSmall.push(i);
    }

    int maxArea = INT_MIN;

    for(int i =0;i<n;i++){
        int height = vec[i];
        int width = right[i] - left[i] -1;

        int area = width*height;

        maxArea = max(area,maxArea);

    }

    cout<<"Max Area is: "<<maxArea<<endl;
}
int main(){
    vector<int> arr ={2,1,5,6,2,3};
    maxArea(arr);

    return 0;
}