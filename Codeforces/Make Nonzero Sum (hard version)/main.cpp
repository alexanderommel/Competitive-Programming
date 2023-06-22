#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 200005;
int a[N];
int dp[N];
int mem[N];
int obj=0;

int g(int la,int lb){
    if (la==lb || a[lb]==0) return 0;
    if(a[lb]==1) return 1;
    else return -1;

}

int s(int i,int n){

    if (i>=n) return 0;
    if(dp[i]!=-1) return dp[i];

    int curr = g(i,i) + s(i+1,n);
    mem[i]=i+1;

    if (i+2<=n+1){
        int quest = s(i+2,n);
        if (quest!=obj){
            quest = quest + g(i,i+1);
            if (quest>curr){
                curr = quest;
                mem[i]=i+2;
            }
        }else{
            curr = obj;
        }

    }
    dp[i]=curr;
    return curr;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int ps=0,ng=0;

        for (int i = 0; i < n; ++i) {
            cin >> a[i+1];
            dp[i+1]=-1;
            if(a[i+1]<0) ng++;
            if(a[i+1]>0) ps++;
        }
        if(((ng+ps)/2)*2!=(ng+ps)){
            cout << -1 <<'\n';
            continue;
        }

        obj = ((ng+ps)/2) - min(ng,ps);

        if (min(ng,ps)==ps){
            for (int i = 0; i < n; ++i) {
                a[i+1]*=-1;
            }
        }

        s(1,n);

        int pp=1;
        int anss=0;
        vector<pair<int,int>> ans;

        while(pp<n){
            ans.emplace_back(pp,mem[pp]-1);
            pp = mem[pp];
            anss++;
        }
        if (pp==n){
            ans.emplace_back(n,n);
            anss++;
        }

        cout << anss<< '\n';
        for(auto par: ans){
            cout << par.first << " "<<par.second<<'\n';
        }
        
    }
}