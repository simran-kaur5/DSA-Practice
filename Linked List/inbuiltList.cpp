#include<iostream>
#include<list>  //inbuilt list in cpp
#include<iterator>  //inbuilt itertors to access list items 
using namespace std;
int main(){

    list<int>ll;
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_front(4);

    // use iterators to print Linked list

    list<int>::iterator itr;
    for(itr = ll.begin();itr!=ll.end();itr++){
        cout<<*(itr)<<"->";
    }

    cout<<endl;
    cout<<"Size of List: "<<ll.size()<<endl;
    cout<<"head of linked list: "<<ll.front()<<endl;
    cout<<"tail of linked list: "<<ll.back()<<endl;
    cout<<endl;
    return 0;
}