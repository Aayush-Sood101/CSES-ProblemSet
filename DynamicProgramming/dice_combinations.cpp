#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;

vector<int> dp;

int ftd(int n){
    if(n == 0) return 1;
    if(dp[n] != -1) return dp[n];
    int count = 0;
    for(int i = 1 ; i<=6 ; i++){
        if(n - i < 0) break;
        count = (count % mod + ftd(n - i) % mod) % mod;
    }
    return dp[n] = (count % mod);
}

int fbu(int n){
    dp[0] = 1;
    
    for(int i = 1 ; i<=n ; i++){
        int count = 0;
        for(int j = 1 ; j<=6 ; j++){
            if(i - j < 0) break;
            count = count % mod + dp[i - j] % mod % mod;
        }
        dp[i] = count % mod;
    }

    return dp[n] % mod;
}

int main(){
    int n;
    cin>>n;
    dp.clear();
    dp.resize(n + 5 , -1);
    cout<<fbu(n);
}