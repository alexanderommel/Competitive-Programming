#include <bits/stdc++.h>
#define PB push_back
#define vi vector<int>
#define FR(n,s,i) for (int i=s; i<n; ++i)
using namespace std;

void sol(int n, vi s, vi d){
    int fires=0,frosts=0;
    int fires_total=0;
    int frosts_total=0;
    vi frs,fts;
    FR(n,0,i){
        if (s[i]==0){
            fires++;
            fires_total+=d[i];
            frs.PB(d[i]);
        }else{
            frosts++;
            frosts_total+=d[i];
            fts.PB(d[i]);
        }
    }
    if (fires==0){
        cout << frosts_total << '\n';
    }
    if (frosts==0){
        cout << fires_total << '\n';
    }
    std::sort(frs.begin(), frs.end());
    std::sort(fts.begin(), fts.end());
    int max_size = max(frs.size(),fts.size());
    int min_size = min(frs.size(),fts.size());
    int total=0;
    bool min_is_fire=false;
    if (frs[0]<fts[0]){
        min_is_fire=true;
    }
    std::sort(frs.begin(), frs.end(), greater<>());
    std::sort(fts.begin(), fts.end(), greater<>());
    FR(max_size,0,i){
        if (i<min_size){
            total+=(2*frs[i]);
            total+=(2*fts[i]);
        }else{
            if (frs.size()>fts.size()){
                total+=frs[i];
            }else{
                total+=fts[i];
            }
        }
    }
    if (min_is_fire){
        total-=frs[frs.size()-1];
    }else{
        total-=fts[fts.size()-1];
    }
    cout << total << '\n';
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vi s,d;
        FR(n,0,i){
            int si;
            cin >> si;
            s.PB(si);
        }
        FR(n,0,i){
            int di;
            cin >> di;
            d.PB(di);
        }
        sol(n,s,d);
    }
}