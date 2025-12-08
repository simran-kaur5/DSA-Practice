#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Egde{
    public:    
    int u;
    int v;
    int wt;

    Egde(int u,int v,int wt){
        this->u =u;
        this->v=v;
        this->wt=wt;
    }
};
class Graph{
    public:
    int V;
    vector<Egde>egde;
    vector<int>par;
    vector<int>rank;

    Graph(int V){
        this->V = V;
        for(int i =0;i<V;i++){
            par.push_back(i);
            rank.push_back(0);
        }
    }

    void addEdge(int u,int v,int wt){
        
        egde.push_back(Egde(u,v,wt));
    }

    int find(int x){
        if(par[x]==x){
            return x;
        }

        return par[x]=find(par[x]);
    }

    void unionByRank(int u,int v){
        int parU = find(u);
        int parV = find(v);


            if(rank[parU]==rank[parV]){
                par[parV]=parU;
                rank[parU]++;
            }else if(rank[parU]>rank[parV]){
                par[parV]=parU;
            }else{
                par[parU]=parV;
            }
        }

        
    void krusKals(){
        int minCost =0;
        sort(egde.begin(),egde.end(),[](Egde &a,Egde &b){return a.wt<b.wt;});

        for(int i =0;i<egde.size();i++){
            Egde e = egde[i];
            int parU = find(e.u);
            int parV = find(e.v);

            if(parU!=parV){   //no cycle condition 
                unionByRank(e.u,e.v);
                minCost+=e.wt;
            }    
        }

        cout<<"Min cost: "<<minCost<<endl;
    }
};

int main(){

    Graph g(4);
    g.addEdge(0,1,10);
    g.addEdge(0,2,15);
    g.addEdge(0,3,30);
    g.addEdge(1,3,40);
    g.addEdge(2,3,50);

    g.krusKals();
    return 0;
}