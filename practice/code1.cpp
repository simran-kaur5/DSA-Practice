#include<iostream>
#include<list>
#include<vector>
#include<queue>
using namespace std;

class Graph{
    list<int>*l;
    int v;

    public:

    Graph(int v){
        this->v = v;
        l = new list<int>[v];
    }
    
    void addEdge(int u,int v){
        l[u].push_back(v);
    }

    void print(){

        for (int i=0;i<v;i++){
            list<int>neigh=  l[i];

            for(int j:neigh){
                cout<<i<<" -> "<<j<<endl;

            } 

            cout<<endl;
        }
    }

    void BFS(){
        vector<bool>vis(v,false);

        queue<int>q;
        q.push(0);
        vis[0] = true;

        while(!q.empty()){
            int u = q.front();
            cout<<u<<" ";
            q.pop();

            list<int>neigh = l[u];

            for(int j:neigh){
                if(!vis[j]){
                    q.push(j);
                    vis[j] = true;
                }
            }
        }
    }

    void dfs(int start,vector<bool>&vis){
        if(vis[start]){
            return;
        }
        
        cout<<start<<" ";
        vis[start]=true;

        list<int>neigh = l[start];
        for(int j:neigh){
            dfs(j,vis);
        }
    }
    void DFS(){
        vector<bool>vis(v,false);   
        for(int i=0;i<v;i++){
            dfs(i,vis);
        }
        
    }

};
int main(){

    Graph g(6);
    g.addEdge(0,1);
    g.addEdge(1,0);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,3);
    g.addEdge(3,5);
    g.addEdge(5,4);

    //g.print();
    g.DFS();


    return 0;
}