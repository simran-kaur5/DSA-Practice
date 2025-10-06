#include<iostream>
using namespace std ;
void towerOfHanoi(int n , string source,string helper , string dest){
    if(n==1){
        cout<<"Move disk 1 from "<<source<<" to "<<dest<<endl;
        return ;
    }

    // go to helper using destination rode
    towerOfHanoi(n-1,source , dest,helper);

    //move largest disk to its correct place
    cout<<"Move disk "<<n<<" from "<<source<<" to "<<dest<<endl;

    //move disk from helper to destination using source
    towerOfHanoi(n-1,helper,source,dest);
}
int main(){
    int n =3;
    towerOfHanoi(n,"A","B","C");
    return 0;

}