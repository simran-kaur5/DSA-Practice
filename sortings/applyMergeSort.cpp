#include<iostream>
#include<vector>
using namespace std;
void mergeSort(vector<string>&vec ,int st , int mid , int end){
    int i = st;
    int j = mid+1;

    vector<string>temp;

    while (i<=mid && j<= end){
        if(vec[j] > vec[i]){
            temp.push_back(vec[i++]);
        }else{
            temp.push_back(vec[j++]);
        }
    }
    
    while(i<=mid){
        temp.push_back(vec[i++]);
    }

    while(j<=end){
        temp.push_back(vec[j++]);
    }

    //push to org

    for(int i = st,x=0;i<=end;i++){
        vec[i] = temp[x++];
    }
    
}
void merge(vector<string>&vec , int st , int end){
    if(end<=st){
        return;
    }
    int mid = st + (end-st)/2;

    merge(vec,st,mid);
    merge(vec,mid+1,end);
    mergeSort(vec,st,mid,end);
}

void print(vector<string>vec){
    for(int i=0;i<vec.size();i++){
        cout<<vec[i]<<" ";
    }
    cout<<endl;
}
int main(){
    vector<string>vec = {"sun","earth","mars","mercury"};
    int n = 4;\
    print(vec);
    merge(vec,0,n-1);
    print(vec);
    return 0;
}