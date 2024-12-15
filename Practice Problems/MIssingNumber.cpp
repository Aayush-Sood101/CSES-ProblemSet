#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){
    int n;
    cin>>n;

    int xorVal = 0;
    for(int i = 0 ; i<n-1 ; i++){
        int val;
        cin>>val;
        //xor of input values
        xorVal = xorVal ^ val;

        //xor of all values from 1 to n - 1
        xorVal = xorVal ^ (i + 1);

    }

    xorVal = xorVal ^ n;
    cout<<xorVal<<endl;

}