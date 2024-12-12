//Steps to reduce n to zero

#include<bits/stdc++.h>
using namespace std;

vector<int> getDigits(int n){
    vector<int> ans;
    while(n > 0){
        if(n % 10 != 0)
        ans.push_back(n % 10);
        n /= 10;
    }
    return ans;
}

vector<int> dp;

int ftd(int n){
    if(n == 0) return 0;
    if(n <= 9) return 1;
    if(dp[n] != -1) return dp[n];
    vector<int> d = getDigits(n);
    int result = INT_MAX;
    for(int i = 0 ; i<d.size() ; i++){
        result = min(result , ftd(n - d[i]));
    }
    return dp[n] = 1 + result;

}

int fbu(int n){
    if(n == 0) return 0;
    if(n <= 9) return 1;

    dp[0] = 0;
    for(int i = 1 ; i<=n ; i++){
        vector<int> d = getDigits(i);
        int result = INT_MAX;
        for(int j = 0 ; j<d.size() ; j++){
            result = min(result , dp[i - d[j]]);
        }
        dp[i] = 1 + result;
    }

    return dp[n];
}

int main(){
    dp.clear();
    dp.resize(1000005 , -1);
    int n;
    cin>>n;
    cout<<fbu(n)<<endl;
}