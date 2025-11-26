#include<iostream>
#include<vector>
#include<queue>
#include<list>
using namespace std;
class Graph{
    int V;
    list<pair<int,int>>*l;
    public:

    Graph(int v){
        V=v;
        l= new list<pair<int,int>>[V];
    }

    void addEdge(int u,int v,int wt){
        l[u].push_back({v,wt});
        l[v].push_back({u,wt});
    }

    void prim(){   //TC -> O(V+E)
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<bool>MSTSet(V,false);
        pq.push({0,0});
        int ans =0;

        while(!pq.empty()){
            pair<int,int>curr = pq.top();
            int cost = curr.first;
            int u = curr.second;
            pq.pop();

            if(!MSTSet[u]){
                ans+=cost;
                MSTSet[u]=true;
                for(pair<int,int> child:l[u]){    
                    if(!MSTSet[child.first]){
                    pq.push({child.second,child.first});
                    }
                }
            }
        }

        cout<<"Minimum cost need: "<<ans<<endl;
    }
};
int main(){
    Graph g(7);
    g.addEdge(0,1,10);
    g.addEdge(0,2,15);
    g.addEdge(0,3,30);
    g.addEdge(1,2,40);
    g.addEdge(2,3,50);

    g.prim();


    return 0;
}