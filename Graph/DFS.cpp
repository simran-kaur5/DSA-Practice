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

    void helper(int u,vector<bool>&vis){
        cout<<u<<" ";
        vis[u] = true;

        for(int child:l[u]){
            if(!vis[child]){
                helper(child,vis);
            }
        }
    }

    void DFS(){   //TC -> O(V+E)
        vector<bool>vis(V,false);
        helper(0,vis);
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
    Graph g(7);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,3);
    g.addEdge(2,4);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.addEdge(3,5);
    g.addEdge(5,6);

    g.DFS();


    return 0;
}