//https://www.spoj.com/problems/MCOINS/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int k , l , m;
    cin>>k>>l>>m;
    vector<int> dp(1000005 , 0);
    dp[1] = 1; dp[k] = 1 ; dp[l] = 1;
    for(int i = 2 ; i<dp.size() ; i++){
        if(i == k || i == l) continue;
        dp[i] = !(dp[i - 1] && ((i - k >= 1) ? dp[i - k] : 1) && ((i - l >= 1) ? dp[i - l] : 1));
    }

    for(int i = 1 ; i<=m ; i++){
        int val;
        cin>>val;
        if(dp[val] == 1){
            cout<<"A";
        }
        else{
            cout<<"B";
        }
    }
}