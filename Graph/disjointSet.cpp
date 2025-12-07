#include<iostream>
#include<vector>
using namespace std;
class disjointSet{
    public:
    int n;
    vector<int>par;
    vector<int>rank;

    disjointSet(int n){
        this->n=n;

        for(int i =0;i<n;i++){
            par.push_back(i);
            rank.push_back(0);
        }
    }

    int find(int x){
        if(par[x]==x){
            return x;
        }

        return par[x]=find(par[x]);
    }

    void unionByRank(int a,int b){
        int par1 = find(a);
        int par2 = find(b);

        if(rank[par1]==rank[par2]){
            par[par2]=par1;
            rank[par1]++;
        }else if(rank[par1]>rank[par2]){
            par[par2]=par1;
        }else{
            par[par1]=par2;
        }
    }
    void print(){
        for(int i =0;i<n;i++){
            cout<<"Rank of "<<i<<" is " <<rank[i]<<" and its parent is "<<par[i]<<endl;
        }
    }
};
int main(){

    disjointSet dj(6);
    dj.unionByRank(0,2);
    dj.find(2);
    dj.unionByRank(1,3);
    dj.unionByRank(2,5);
    dj.find(2);
    dj.unionByRank(0,4);
    dj.unionByRank(0,3);
    dj.print();

    return 0;
}