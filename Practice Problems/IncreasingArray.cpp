#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){
    int n;
    cin>>n;
    ll moves = 0;
    int pVal;
    cin>>pVal;

    for(int i = 1 ; i<n ; i++){
        int val;
        cin>>val;
        if(val < pVal)
        moves += (abs(pVal - val));
        else
        pVal = val;
    }

    cout<<moves<<endl;
}