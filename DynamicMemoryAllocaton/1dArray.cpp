#include <iostream>
using namespace std;
int main(){

    //dynamic array -> arrays which resizes its array according to their need.
    int size;
    cout<<"Enter size of Array: "<<endl;
    cin>>size;
    int *arr = new int [size]; //gets memory at run time
     
   //new -> this keyWord allocates dyanmic memory to array
   int x = 0;
    for(int i =0;i<size;i++){
        arr[i]=x++;
        cout<<arr[i]<<" ";
    }

    //whenever we allocates dynamic memory to any data structure we have to delete it manually by using <-delete-> keyword

    delete [] arr;  //deallocates memory
    cout<<endl;
    return 0;
}