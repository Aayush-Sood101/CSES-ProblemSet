#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    vector<int> arrival(n);
    vector<int> departure(n);

    for(int i = 0 ; i<n ; i++){
        cin>>arrival[i];
        cin>>departure[i];
    }

    sort(arrival.begin() , arrival.end());
    sort(departure.begin() , departure.end());

    int i = 0 , j = 0;
    int currentCusomers = 0;
    int maxCustomers = 0;

    while(i < n && j < n){
        if(arrival[i] < departure[j]){
            currentCusomers++;
            maxCustomers = max(currentCusomers , maxCustomers);
            i++;
        }
        else{
            currentCusomers--;
            j++;
        }
    }

    cout<<maxCustomers<<endl;
}