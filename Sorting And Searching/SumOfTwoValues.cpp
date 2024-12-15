#include<bits/stdc++.h>
#define ll long long int
#define pll pair<ll , ll>
using namespace std;

int main(){
    int n , target;
    cin>>n>>target;

    vector<pll> v(n);
    for(int i = 0 ; i<n ; i++){
        ll val;
        cin>>val;
        v[i] = {val , i + 1};
    }

    sort(v.begin() , v.end());

    int i = 0 , j = n - 1;
    bool flag = true;
    while(i < j){
        ll sum = v[i].first + v[j].first;
        if(sum == target){
            flag = false;
            ll val1 = v[i].second;
            ll val2 = v[j].second;
            if(val1 < val2)
            cout<<val1<<" "<<val2<<endl;
            else
            cout<<val2<<" "<<val1<<endl;
            break;
        }
        else if(sum < target)
        i++;
        else
        j--;
    }
    if(flag)
    cout<<"IMPOSSIBLE"<<endl;

}