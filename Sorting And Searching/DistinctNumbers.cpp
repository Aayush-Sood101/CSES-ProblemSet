#include<bits/stdc++.h>
using namespace std;

//use set instead of unordered_set

int main(){
    int n;
    cin>>n;
    set<int> s;
    for(int i = 0 ; i<n ; i++){
        int val;
        cin>>val;
        s.insert(val);
    }

    cout<<s.size()<<endl;
}