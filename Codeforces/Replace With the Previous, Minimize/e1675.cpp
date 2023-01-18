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

typedef std::pair<ll,ll> mypair;
bool my_comparator ( const mypair& l, const mypair& r){
    return l.second > r.second;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        string s;
        cin >> s;
        int l=0;
        char w='a';
        vector<pair<int,int>> ANS;
        fr(0,n,i){

            if(s[i]<=w){
                continue;
            }else{
                if(s[i]-w>=k){
                    ANS.pb({s[i]-k,s[i]});
                    k=0;
                    break;
                }else{
                    ANS.pb({w,s[i]});
                    k-=(s[i]-w);
                    w=s[i];
                }
            }
        }
        std::sort(ANS.begin(), ANS.end(), my_comparator);
        fr(0,n,i){
            fr(0,ANS.size(),j){
                char comparer = ANS[j].second;
                if(s[i]-'a'<=comparer-'a'){
                    char rest = ANS[j].first;
                    char ops = min(s[i]-'a',rest-'a')+'a';
                    s[i]=ops;
                }
            }
            cout << s[i];
        }
        cout << '\n';
    }
    return 0;
}