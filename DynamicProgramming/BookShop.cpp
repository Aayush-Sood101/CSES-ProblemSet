#include<bits/stdc++.h>
using namespace std;

//TOP DOWN SOLUTION WILL GIVE TLE

vector<vector<int>> dp;
int ftd(int n , int x , vector<int> cost , vector<int> pages){
    if(n == 0) return (x >= cost[0]) ? pages[0] : 0;
    if(dp[n][x] != -1) return dp[n][x];
    return dp[n][x] = max(( (x - cost[n] >= 0) ? pages[n] + ftd(n - 1 , x - cost[n] , cost , pages) : INT_MIN ), ftd(n - 1 , x , cost, pages));
}

int fbu(int x , vector<int> &cost , vector<int> &pages){
    int n = pages.size();
    vector<int> dp(x + 1, 0);
    
    // Iterative DP
    for (int i = 0; i < n; i++) {
        for (int j = x; j >= cost[i]; j--) {
            dp[j] = max(dp[j], dp[j - cost[i]] + pages[i]);
        }
    }
    
    return dp[x];
}

int main(){
    int n , x;
    cin>>n>>x;
    dp.clear();
    dp.resize(n + 5 , vector<int> (x + 5 , -1));
    vector<int> cost(n);
    vector<int> pages(n);
    for(int i = 0 ; i<n ; i++){
        cin>>cost[i];
    }

    for(int i = 0 ; i<n ; i++){
        cin>>pages[i];
    }

    cout<<fbu(x , cost , pages)<<endl;
}