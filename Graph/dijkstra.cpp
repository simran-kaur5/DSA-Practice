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

void dijkStra(int src,vector<vector<Edge>>&graph,int V){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    vector<int>dis(V,INT_MAX);
    dis[src]=0;
    pq.push({0,src});

    while(pq.size()>0){
        int curr = pq.top().second;
        pq.pop();

        vector<Edge>edges = graph[curr];
        for(Edge edge:edges){
            if(dis[edge.v]> dis[curr]+edge.wt){
                dis[edge.v]=dis[curr]+edge.wt;
                pq.push({dis[edge.v],edge.v});
            }
        }
    }

    for(int i=src;i<V;i++){
        cout<<dis[i]<<" ";
    }

}
int main(){
    int V =6;
    vector<vector<Edge>>graph(V);

    graph[0].push_back(Edge(2,4));
    graph[0].push_back(Edge(1,2));

    graph[1].push_back(Edge(3,7));
    graph[1].push_back(Edge(2,1));

    graph[2].push_back(Edge(4,3));

    graph[3].push_back(Edge(5,1));

    graph[4].push_back(Edge(3,2));
    graph[4].push_back(Edge(5,5));

    dijkStra(0,graph,V);

}