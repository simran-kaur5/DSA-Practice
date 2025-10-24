#include<iostream>
#include<queue>
using namespace std;
string nonRep(string s){
    queue<char>q;
    string ans ="";

    int freq[26]= {0};

    for(char ch:s){
        q.push(ch);
        freq[ch-'a']++;

        while(!q.empty() && freq[q.front() - 'a'] >1){
            q.pop();
        }

        if(q.empty()){
            ans+="-1";
        }else{
            ans+=q.front();
        }
    }
    return ans;
}
int main(){

    string str = "aabccxb";
    cout<<"First non repeating character is: "<<nonRep(str)<<endl;
    return 0;
}