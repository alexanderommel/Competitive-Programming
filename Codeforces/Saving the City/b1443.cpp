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

void sol(int Y,int X,string s){
    vector<pair<int,int>> SQ;
    if (s.size()==1){
        if (s[0]=='1'){
            cout << Y << '\n';
            return;
        }
    }
    int p1=-1;
    int p2=p1;
    fr(0,s.size(),i){
        if (i==s.size()-1){
            if (s[i]=='1'){
                if (p1!=-1){
                    SQ.pb({p1,p2+1});
                }else{
                    SQ.pb({i+1,i+1});
                }
                break;
            }
        }
        if (s[i]=='0'){
            if (p1!=-1){
                SQ.pb({p1,p2});
                p1=-1;
            }
        }else{
            if (p1==-1){
                p1=i+1;
                p2=p1;
            }else{
                p2++;
            }
        }
    }
//    fr(0,SQ.size(),i){
//        cout << "Pair ("<<SQ[i].first<<","<<SQ[i].second<<")"<<'\n';
//    }
    if(SQ.empty()){
        cout << 0 <<'\n';
        return;
    }
    pair<int,int> current=SQ[0];
    int ans=0;
    fr(1,SQ.size(),i){
        int k = SQ[i].first-current.second-1;
        int g = X*k;
        if (g>=Y){
            ans+=Y;
            current = {SQ[i].first,SQ[i].second};
        }else{
            ans+=g;
            current = {0,SQ[i].second};
        }
    }
    ans+=Y;
    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        int Y,X;
        cin >> Y >> X;
        string s;
        cin >> s;
        sol(Y,X,s);
    }

    return 0;
}
