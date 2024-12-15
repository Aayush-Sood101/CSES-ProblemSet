#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;

ll logPower(int a , int b){
    if(b == 0 || b == 1) return a;
    
    ll ans = logPower(a , b / 2) % mod;
    if(b % 2 == 0)
    return ((ans % mod) * (ans % mod) % mod);
    else
    return (a * (ans % mod) * (ans % mod)) % mod;
}

int main(){
    int n;

    cin>>n;

    cout<<logPower(2 , n)<<endl;
}