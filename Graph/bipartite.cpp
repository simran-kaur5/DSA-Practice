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

    void print(){
        for(int idx=0;idx<V;idx++){
            
            cout<<idx<<" : [ ";
            for(int child:l[idx]){
                cout<<"[ "<<child<<"] ";
            }
            cout<<" ] ";
            cout<<endl;
        }
    }

    bool bipartite(){
        queue<int>q;
        vector<int>color(V,-1);
        q.push(0);
        color[0]=0;

        while(!q.empty()){
            int curr = q.front();
            q.pop();

            for(int child:l[curr]){
                if(color[child] ==-1){
                    color[child] =!color[curr];
                    q.push(child);
                }else{
                    if(color[child]==color[curr]){
                        return false;
                    }
                }
            }
        }

        return true ;
    }

};
int main(){
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,0);

    if(g.bipartite()){
        cout<<"graph is bipartite."<<endl;
    }else{
        cout<<"graph is not bipartite."<<endl;
    }


    return 0;
}