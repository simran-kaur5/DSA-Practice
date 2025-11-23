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

    void helper(int src,int des,vector<bool>&vis,string &path){
        if(src==des){
            cout<<path<<des<<endl;
            return;
        }
        vis[src]=true;
        path+=to_string(src);

        for(int child:l[src]){
            if(!vis[child]){
                helper(child,des,vis,path);
            }
        }

        path.pop_back();
        vis[src]=false;
    }

    void DFS(){   
        vector<bool>vis(V,false);
        int src =5,des=1;
        string path = "";
        helper(src,des,vis,path);
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
    g.addEdge(5,2);
    g.addEdge(2,3);
    g.addEdge(3,1);
    g.addEdge(4,1);
    g.addEdge(4,0);
    g.addEdge(5,0);
    g.addEdge(0,3);


    g.DFS();


    return 0;
}