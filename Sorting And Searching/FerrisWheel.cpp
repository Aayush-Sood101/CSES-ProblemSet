#include<bits/stdc++.h>
using namespace std;

int main(){
    int n , x;
    cin>>n>>x;
    vector<int> v(n);

    for(int i = 0 ; i<n ; i++){
        cin>>v[i];
    }

    sort(v.begin() , v.end());

    int cnt = 0;
    int i = 0 , j = n - 1;
    while(i < j){
        if(v[i] + v[j] <= x){
            cnt++;
            i++;
            j--;
        }
        else{
            cnt++;
            j--;
        }
    }
    if(i == j) cnt++;
    cout<<cnt<<endl;
}