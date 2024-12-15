#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    if(n == 2 || n == 3){
        cout<<"NO SOLUTION"<<endl;
        return 0;
    }

    if(n == 4){
        cout<<"2 4 1 3"<<endl;
        return 0;
    }

    int org_n = n;
    while(org_n >= 1){
        cout<<org_n<<" ";
        org_n -= 2;
    }

    org_n = n - 1;
    while(org_n >= 1){
        cout<<org_n<<" ";
        org_n -= 2;
    }

}