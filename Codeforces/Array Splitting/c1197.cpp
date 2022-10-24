#include <bits/stdc++.h>
#define pb push_back
#define vi vector<int>
#define fr(s,n,i) for (long long i=s; i<n; ++i)
#define fri(s,e,i) for (long long i=s; i>=e; --i)
using namespace std;

bool my_operator(const pair<int,int> a, const pair<int,int> b){
    return a.first > b.first;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n,k;
    cin >> n >> k;
    int a[n];
    vi LEFT;
    vector<pair<int,int>> ans;
    fr(0,n,i){
        cin >> a[i];
        if (i==0){
            LEFT.pb(0);
        }else{
            LEFT.pb(a[i]-a[0]);
        }
    }

    if (n==k){
        cout << 0 << '\n';
        return 0;
    }

    fri(n-1,0,i){
        int right;
        if (i==n-1){
            right = 0;
        }else{
            right = a[n-1]-a[i];
        }
        int left;
        if (i>0){
            left = LEFT[i-1];
        }else{
            left = 0;
        }
        ans.pb({right + left,i});
    }
    std::sort(ans.begin(), ans.end(), my_operator);
    vector<pair<int,int>> intervals;
    int rr=n-1;
    fr(0,k,h){
        int lft;
        if (h==k-1){
            lft=0;
        }else{
            lft = ans[n-1-h].second;
        }
        intervals.pb({lft,rr});
        rr = lft-1;
    }
    int best=0;
    fr(0,k,i){
        best+=(a[intervals[i].second]-a[intervals[i].first]);
    }
    cout << best << '\n';

    return 0;
}
