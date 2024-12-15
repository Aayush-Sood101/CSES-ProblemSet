#include<bits/stdc++.h>
using namespace std;

int main(){
    string str;
    cin>>str;

    int n = str.length();

    int maxLen = 0;
    int i = 0;
    int j = 0;
    while(i < n && j<n){
        while(str[j] == str[i])
        j++;

        int len = j - i;
        if(len > maxLen)
        maxLen = len;
        
        i = j;
    }

    int len = j - i;
    cout<<max(len , maxLen)<<endl;
}