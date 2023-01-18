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
    return l.second < r.second;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<pair<int,int>> a;
        fr(0,n,i){
            int ai;
            cin >> ai;
            if(ai!=0){
                a.pb({ai,i+1});
            }
        }
        std::sort(a.begin(), a.end(), my_comparator);
        make_heap(a.begin(),a.end());
        vector<pair<int,int>> ANS;
        while(true){

            if (a.empty() || a.size()==1){
                break;
            }

            pair<int,int> maxxx  = a.front();
            pop_heap(a.begin(),a.end());
            a.pop_back();

            pair<int,int> submax  = a.front();
            pop_heap(a.begin(),a.end());
            a.pop_back();

            ANS.pb({submax.second,maxxx.second});

            pair<int,int> subs1 = {maxxx.first-1,maxxx.second};
            pair<int,int> subs2 = {submax.first-1,submax.second};

            if (subs1.first!=0){
                a.push_back(subs1);
                push_heap(a.begin(),a.end());
            }

            if (subs2.first!=0){
                a.push_back(subs2);
                push_heap(a.begin(),a.end());
            }

        }
        cout << ANS.size() << '\n';
        fr(0,ANS.size(),k){
            cout << ANS[k].first << " " << ANS[k].second << '\n';
        }
    }

    return 0;
}