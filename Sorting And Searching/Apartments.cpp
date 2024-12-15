#include<bits/stdc++.h>
using namespace std;

int main(){
    //n - number of applicants
    //m - number of apartments
    //k - max allowed difference
    int n , m , k;
    cin>>n>>m>>k;

    vector<int> applicant(n);
    vector<int> appartment(m);
    for(int i = 0 ; i<n ; i++)
    cin>>applicant[i];

    for(int i = 0 ; i<m ; i++)
    cin>>appartment[i];

    sort(applicant.begin() , applicant.end());
    sort(appartment.begin() , appartment.end());
    int i = 0 , j = 0;
    int cnt = 0;
    while(i < n && j < m){
        if(abs(applicant[i] - appartment[j]) <= k){
            cnt++;
            i++;j++;
        }
        else if(applicant[i] > appartment[j])
        j++;
        else
        i++;
    }

    cout<<cnt<<endl;
}