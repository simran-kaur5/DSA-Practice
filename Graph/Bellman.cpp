#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<climits>
using namespace std;
class Edge{
    public:
    int v;
    int wt;

    Edge(int v,int wt){
        this->v = v;
        this->wt=wt;
    }
};

void Bellman(int src,vector<vector<Edge>>&graph,int V){
    vector<int>dis(V,INT_MAX);
    dis[src]=0;
    
    for(int i =0;i<V-1;i++){// TC-> O(V*E)
        for(int j =0;j<V;j++){
            for(Edge e:graph[j]){
                if(dis[e.v]>dis[j]+e.wt){
                    dis[e.v]=dis[j]+e.wt;
                }
            }
        }
    }

    for(int i =0;i<dis.size();i++){
        cout<<dis[i]<<" ";
    }

}
int main(){
    int V =5;
    vector<vector<Edge>>graph(V);

    graph[0].push_back(Edge(2,4));
    graph[0].push_back(Edge(1,2));

    graph[1].push_back(Edge(2,-4));

    graph[2].push_back(Edge(3,2));

    graph[3].push_back(Edge(4,4));

    graph[4].push_back(Edge(1,-1));

    Bellman(4,graph,V);

}