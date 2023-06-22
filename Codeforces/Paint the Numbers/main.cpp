#include<bits/stdc++.h>
int n,i,j,f,a[101];
int main(){
    for(scanf("%d",&n);i<n;i++)scanf("%d",a+i);
    std::sort(a,a+n);
    for(;f=0,i--;n-=f)for(j=i;j--;)f|=a[i]%a[j]<1;
    printf("%d",n);
}