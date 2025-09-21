#include <iostream> 
#include <vector> //header file for vector
using namespace std;
int main(){
    //whenever size == capacity aafter that we push a elememt the capacity becomes = capacity*2  and intenally the memory is realloacted to vector int big size vector
    vector<int>vec;
    cout<<"Size of vector: "<<vec.size()<<endl; //size of vector-> 0
    cout<<"Capacity of vector: "<<vec.capacity()<<endl;  //capacity of vector -> 0
    vec.push_back(1); //adds element at last of vector
    cout<<"Size of vector: "<<vec.size()<<endl; //size of vector-> 1
    cout<<"Capacity of vector: "<<vec.capacity()<<endl;  //capacity of vector -> 1
    vec.push_back(2);
    cout<<"Size of vector: "<<vec.size()<<endl; //size of vector-> 2
    cout<<"Capacity of vector: "<<vec.capacity()<<endl;  //capacity of vector -> 2
    vec.push_back(4);
    cout<<"Size of vector: "<<vec.size()<<endl; //size of vector-> 3
    cout<<"Capacity of vector: "<<vec.capacity()<<endl;  //capacity of vector -> 4
    vec.push_back(5);
    cout<<"Size of vector: "<<vec.size()<<endl; //size of vector-> 4
    cout<<"Capacity of vector: "<<vec.capacity()<<endl;  //capacity of vector -> 4
    vec.push_back(7);
    cout<<"Size of vector: "<<vec.size()<<endl; //size of vector-> 5
    cout<<"Capacity of vector: "<<vec.capacity()<<endl;  //capacity of vector -> 8
    return 0;
}