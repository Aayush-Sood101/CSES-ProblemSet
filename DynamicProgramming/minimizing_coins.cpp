#include<bits/stdc++.h>
using namespace std;

vector<int> dp;

int ftd(int n , vector<int> &coins){
    if(n == 0) return 0;
    if(dp[n] != -1) return dp[n];
    int result = INT_MAX;
    for(int i = 0 ; i<coins.size() ; i++){
        if(n - coins[i] < 0) continue;
        result = min(result , ftd(n - coins[i] , coins));

    }

    return dp[n] = (result == INT_MAX) ? result : 1 + result;
}

int main(){
    int k , n;
    cin>>k>>n;
    dp.clear();
    dp.resize(1000005 , -1);
    vector<int> coins(k);
    for(int i = 0 ; i<k ; i++)
    cin>>coins[i];

    int ans = ftd(n , coins);

    cout<<((ans == INT_MAX) ? "-1" : to_string(ans))<<endl;
}