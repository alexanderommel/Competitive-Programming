#include <bits/stdc++.h>
#define int long long int
using namespace std;
 
const int MAXN = 2e5;
int n,t[4*MAXN];
 
void build(int a[], int v, int tl, int tr){
    if (tl==tr){ // leaf node
        t[v]=a[tl];
    }else{
        int tm = (tl+tr)/2; // interval middle
        build(a,v*2,tl,tm);
        build(a,v*2 + 1, tm+1, tr);
        t[v]= t[v*2]+t[v*2 + 1];
    }
}
 
int sum(int v, int tl, int tr, int l, int r){
    if (l>r) return 0;
    if (l==tl && r==tr){
        return t[v];
    }
    int tm = (tl + tr)/2;
    return sum(v*2,tl,tm,l,min(r,tm)) + sum(v*2 + 1, tm+1, tr,max(l,tm+1),r);
}
 
void update(int v, int new_value, int index, int tl, int tr){
    if (tl==tr){
        t[v]=new_value;
        return;
    }
    int tm = (tl+tr)/2;
    if (index<=tm) update(v*2,new_value,index,tl,tm);
    else update(v*2+1,new_value,index,tm+1,tr);
    t[v]=t[v*2]+t[v*2+1];
}
 
 
signed main(){
    cin >> n;
    int q; cin >> q;
    int inp[n];
    for (int i = 0; i < n; ++i) {
        cin >> inp[i];
    }
    build(inp,1,0,n-1);
    while(q--){
        int a,b,c; cin >> a >> b >> c;
        if (a==1){
            update(1,c,b-1,0,n-1);
            continue;
        }
        cout << sum(1,0,n-1,b-1,c-1)<<'\n';
    }
}