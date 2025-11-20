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
    }

    bool cycleDetect(int u,vector<bool>&vis,vector<bool>&recPath){
        vis[u]=true;
        recPath[u]=true;
        
        for(int neigh:l[u]){
            if(!vis[neigh]){
                if(cycleDetect(neigh,vis,recPath)){
                    return true;
                }
            }else{
                if(recPath[u]==true){
                    return true;
                }
            }
        }
        recPath[u]=false;
        return false;
    }

    bool DFS(){
        vector<bool>recPath(V,false);
        vector<bool>vis(V,false);

        return cycleDetect(0,vis,recPath);  //we need also access of parent so we pass -1 for first node parent
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
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,0);

    if(g.DFS()){
        cout<<"Cycle is detected."<<endl;
    }else{
        cout<<"Cycle is not present."<<endl;
    }

    return 0;
}