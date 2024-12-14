#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long int
using namespace std;
 
 //TOP DOWN SOLUTION DOES NOT SUBMIT DUE TO LARGE NUMBER OF RECUSRSIVE CALLS


vector<int> dp;

int f(int target , vector<int> coins){
    if(target == 0) return 1;
    if(target < 0) return 0;
    if(dp[target] != -1) return dp[target];
    ll count = 0;
    for(int i = 0 ; i<coins.size() ; i++){
        if(target - coins[i] < 0) break;
        count = (count % mod  + f(target - coins[i] , coins) % mod) % mod;
    }

    return dp[target] = count % mod;
}

int fbu(int target , vector<int> coins){
    dp[0] = 1;
    for(int i = 1 ; i<=target ; i++){
        int count = 0;
        for(int j = 0 ; j<coins.size() ; j++){
            if(i - coins[j] >= 0) 
            count = (count % mod + dp[i - coins[j]] % mod) % mod;
        }
        dp[i] = count % mod;
    }
    return dp[target];
}

int main(){
    dp.clear();
    dp.resize(1000005, -1);
    int n;
    int target;
    cin>>n>>target;
    vector<int> coins(n);
    for(int i = 0 ; i<n ; i++)
    cin>>coins[i];

    sort(coins.begin() , coins.end());

    cout<<fbu(target , coins)<<endl;
}