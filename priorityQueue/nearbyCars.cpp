#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Car{
    public:
    int idx;
    int dis;
    Car(int idx,int dis){
        this->idx = idx;
        this->dis= dis;
    }

    bool operator < (const Car &obj) const{
        return this->dis > obj.dis;
    }
};

void nearbyCar(vector<pair<int,int>>vec,int k){
    vector<Car>cars;

    for(int i =0;i<vec.size();i++){
        int disSq = (vec[i].first*vec[i].first) + (vec[i].second * vec[i].second);
        cars.push_back(Car(i,disSq));
    }

    priority_queue<Car>pq(cars.begin(),cars.end());

    for(int i =0;i<k;i++){
        cout<<pq.top().idx<<" ";
        pq.pop();
    }
    
}
int main(){

    vector<pair<int,int>>vec;
    vec.push_back(make_pair(3,3));
    vec.push_back(make_pair(5,-1));
    vec.push_back(make_pair(-2,4));

    int k =2;
    nearbyCar(vec,k);

    return 0;
}