#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Row{
    public:
    int count;
    int idx;
    Row(int count,int idx){
        this->count = count;
        this->idx = idx;
    }

    bool operator < (const Row &obj) const{
        if(this->count==obj.count){
            return this->idx > obj.idx;
        }

        return this->count > obj.count;
    }
};
void soldier(vector<vector<int>>mat,int k){
    vector<Row>vec;
    for(int i=0;i<mat.size();i++){
        int count =0;
        for(int j=0;j<mat[0].size() && mat[i][j]==1;j++){
            count++;
        }
        vec.push_back(Row(count,i));
    }

    priority_queue<Row>pq(vec.begin(),vec.end());

    for(int i=0;i<k;i++){
        cout<<"Row"<<pq.top().idx<<endl;
        pq.pop();
    }

}
int main(){
    vector<vector<int>>mat={
        {1,0,0,0},
        {1,1,1,1},
        {1,0,0,0},
        {1,0,0,0}
    };

    soldier(mat,2);

    return 0;
}