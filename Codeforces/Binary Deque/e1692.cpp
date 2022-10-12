#include <bits/stdc++.h>
#define PB push_back
#define vi vector<int>
#define FR(n,s,i) for (int i=s; i<n; ++i)
using namespace std;

void sol2(int n, int s, vi a){

    int ONESS=0;
    FR(n,0,i){
        if (a[i]==1)
            ONESS++;
    }
    if (ONESS<s){
        cout << "-1" << '\n';
        return;
    }
    if (ONESS==s){
        cout << 0 << '\n';
        return;
    }

    int PS[n];
    int sum=0;
    FR(n,0,i){
        if(a[i]==1){
            ++sum;
        }
        PS[i]=sum;
    }
    int MIN_STEPS=INT_MAX;
    FR(n,0,i){
        int L=i;
        int R=n-1;
        int rp;
        int MAX_R=INT_MIN;
        while(L<=R){
            rp = (L+R)/2;
            int ONES = PS[rp]-PS[i]+a[i];
            if (ONES<s){
                L = rp+1;
            }
            if (ONES==s){
                L=rp+1;
                MAX_R = max(MAX_R,rp);
            }
            if(ONES>s){
                R = rp-1;
            }
        }
        int stps = n-(MAX_R-i+1);
        if (MAX_R==INT_MIN || PS[MAX_R]-PS[i]+a[i]!=s){
            continue;
        }
        MIN_STEPS = min(MIN_STEPS,stps);
    }
    cout << MIN_STEPS << '\n';
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,s;
        cin >> n >> s;
        vi a;
        FR(n,0,i){
            int x;
            cin >> x;
            a.PB(x);
        }
        sol2(n,s,a);
    }
}