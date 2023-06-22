#include<bits/stdc++.h>
using namespace std;
int n,i=1,j,k,a;
int main(){
    for(cin>>n;i<=n;i++){
        cin>>a;a?j=i:k=i;
    }
    cout<<min(j,k);
}