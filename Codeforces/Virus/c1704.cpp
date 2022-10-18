#include <bits/stdc++.h>
#define pb push_back
#define vi vector<int>
#define ll long long
#define vll vector<long long>
#define fr(s,n,i) for (long long i=s; i<n; ++i)
#define fri(s,e,i) for (long long i=s; i>=e; --i)
#define len(arr) arr.size()
#define viin(vec,n) fr(0,n,i){int x; cin>>x; vec.pb(x);}
#define vllin(vec,n) fr(0,n,i){ll x; cin>>x; vec.pb(x);}
using namespace std;

void sol(int n,int m,vi infected){
    std::sort(infected.begin(), infected.end());
    vi I;
    fr(1,m,i){
        int len = infected[i]-infected[i-1]-1;
        I.pb(len);
    }
    int origin = n + infected[0];
    I.pb(origin-infected[m-1]-1);
    std::sort(I.begin(), I.end());
    int day=1;
    int ac = 0;
    int p_houses=0;
    int iv = I.size()-1;
    while(iv>=0){
        if (day%2==0){
            p_houses+=I[iv];
            I[iv]=0;
        }else{
            m+=min(ac,I[iv]);
            I[iv]-=ac;
            if (I[iv]<=0){
                iv--;
                continue;
            }
            p_houses+=1;
            I[iv]-=1;
            if (I[iv]<=0){
                iv--;
                ac+=2;
                continue;
            }
            ++m;
        }
        ac+=2;
        day++;
    }
    cout << m << '\n';
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        vi infected;
        viin(infected,m);
        sol(n,m,infected);
    }
}