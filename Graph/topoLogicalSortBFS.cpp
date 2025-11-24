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

    void inDegree(vector<int>&inD){

        for(int i=0;i<V;i++){
            for(int child:l[i]){
                inD[child]++;
            }
        }
    }

    void topoLogical(){  //also known as Kahn's Algo
        vector<int>inD(V,0);
        inDegree(inD);
        queue<int>q;

        //push to queue nodes having 0 inOrder degree
        for(int i =0;i<V;i++){
            if(inD[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int curr = q.front();
            q.pop();
            cout<<curr<<" ";

            for(int child:l[curr]){
                inD[child]--;
                if(inD[child]==0){
                    q.push(child);
                }
            }
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
    g.addEdge(4,0);
    g.addEdge(4,1);
    g.addEdge(3,1);
    g.addEdge(2,3);
    g.addEdge(5,0);
    g.addEdge(3,0);
    g.addEdge(5,2);
    // g.addEdge(5,6);

    g.topoLogical();


    return 0;
}