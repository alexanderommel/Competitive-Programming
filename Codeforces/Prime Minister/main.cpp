#include<bits/stdc++.h>
using namespace std;
int n,k,i,s,r,a[179];
int main(){
for(cin>>n;i<n;i++)cin>>a[i],s+=a[i];
for(i=1,r=a[0];i<n;i++)if(a[i]+a[i]<=a[0])r+=a[i],k++;
if(r+r<=s)return cout<<0,0;
cout<<k+1<<"\n1 ";
for(i=1;i<n;i++)if(a[i]+a[i]<=a[0])cout<<i+1<<" ";
}