#include<iostream>
#include<vector>
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

    void addEdge(int u,int v,int c){
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void print(){
        for(int idx=0;idx<V;idx++){
            
            cout<<idx<<" : [ ";
            for(int i:l[idx]){
                cout<<i;
            }
            cout<<" ] ";
            cout<<endl;
        }
    }
};
int main(){
    Graph g(4);
    g.addEdge(0,1,5);
    g.addEdge(1,2,1);
    g.addEdge(1,3,3);
    g.addEdge(2,3,1);

    g.print();


    return 0;
}