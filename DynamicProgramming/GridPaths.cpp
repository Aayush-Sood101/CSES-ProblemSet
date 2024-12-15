#include<bits/stdc++.h>
#define ll long long int
#define mod 1000000007
using namespace std;

vector<vector<ll>> dp;

ll ftd(int sr , int sc , vector<vector<int>> grid){
    if(sr == 1 && sc == 1) return 1;
    if(sr == 0 || sc == 0) return 0;
    if(dp[sr - 1][sc - 1] != -1) return dp[sr - 1][sc - 1];
    if(grid[sr - 1][sc - 1] == 1) 
    return dp[sr - 1][sc - 1] = 0;
    else
    return dp[sr - 1][sc - 1] = (ftd(sr - 1, sc , grid) % mod + ftd(sr , sc - 1 , grid) % mod) % mod;

}

int fbu(vector<vector<int>> grid){
    int n = grid.size();
    dp[0][0] = 1;
    for(int i = 0 ; i<n ; i++){
        for(int j = 0 ; j<n ; j++){
            if(i == 0 && j == 0) continue;
            else if(grid[i][j] == 1)
            dp[i][j] = 0;
            else if(i == 0 && dp[i][j - 1] == 0)
            dp[i][j] = 0;
            else if(j == 0 && dp[i - 1][j] == 0)
            dp[i][j] = 0;
            else if(i == 0 || j == 0)
            dp[i][j] = 1;
            else
            dp[i][j] = (dp[i - 1][j] % mod + dp[i][j - 1] % mod) % mod;
        }
    }
    
    return dp[n - 1][n - 1];
}

int main(){
    int n;
    cin>>n;
    dp.clear();
    dp.resize(n + 5 , vector<ll> (n + 5 , -1));
    vector<vector<int>> grid(n , vector<int> (n , -1));
    for(int i = 0 ; i<n ; i++){
        for(int j = 0 ; j<n ; j++){
            char ch;
            cin>>ch;
            if(ch == '.')
            grid[i][j] = 0;
            else
            grid[i][j] = 1;
        }
    }
    if(grid[0][0] == 1)
    cout<<"0"<<endl;
    else
    cout<<fbu(grid)<<endl;
}