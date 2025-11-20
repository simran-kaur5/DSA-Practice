#include<iostream>
#include<vector>
#include<queue>
#include<list>
using namespace std;
class Graph{
    int V;
    list<int>*l;
    public:

    Graph(int v){
        V=v;
        l= new list<int>[V];
    }

    void addEdge(int u,int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }

    bool cycleDetect(int u,vector<bool>&vis,int par){
        vis[u]=true;
        
        for(int neigh:l[u]){
            if(!vis[neigh]){
                if(cycleDetect(neigh,vis,u)){
                    return true;
                }
            }else{
                if(par != u){
                    return true;
                }
            }
        }

        return false;
    }

    bool DFS(){
        vector<bool>vis(V,false);
        return cycleDetect(0,vis,-1);  //we need also access of parent so we pass -1 for first node parent
    }

    void print(){
        for(int idx=0;idx<V;idx++){
            
            cout<<idx<<" : [ ";
            for(int v :l[idx]){
                cout<<"[ "<<v<<"] ";
            }
            cout<<" ] ";
            cout<<endl;
        }
    }
};
int main(){
    Graph g(3);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(0,2);

    if(g.DFS()){
        cout<<"Cycle is detected."<<endl;
    }else{
        cout<<"Cycle is not present."<<endl;
    }

    return 0;
}