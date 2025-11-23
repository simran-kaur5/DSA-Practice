#include<iostream>
#include<vector>
#include<stack>
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

    void helper(int u,vector<bool>&vis,stack<int>&s){
       vis[u] = true;

        for(int child:l[u]){
            if(!vis[child]){
                helper(child,vis,s);
            }
        }
        s.push(u);
    }

    void topoLogicalSort(){   //TC -> O(V+E)   , SC -> O(V)
        stack<int>s;
        vector<bool>vis(V,false);
    
        for(int i=0;i<V;i++){
            if(!vis[i]){
                helper(i,vis,s);
            }
        }
        

        while(!s.empty()){
            cout<<s.top()<<" ";
            s.pop();
        }
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
    Graph g(6);
    g.addEdge(5,0);
    g.addEdge(2,3);
    g.addEdge(4,1);
    g.addEdge(3,1);
    g.addEdge(5,2);
    g.addEdge(4,0);

    g.topoLogicalSort();


    return 0;
}