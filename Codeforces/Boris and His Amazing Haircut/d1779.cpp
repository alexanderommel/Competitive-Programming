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

struct greaters{
    bool operator()(const int& a,const int& b) const{
        return a>b;
    }
};

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n ;
        int a[n];
        int b[n];
        vi c;
        fr(0,n,i){
            cin >> a[i];
        }
        fr(0,n,i){
            cin >> b[i];
        }
        int m;
        cin >> m;
        fr(0,m,i){
            int x;
            cin >> x;
            c.pb(x);
        }

        vi f;
        vi ans;
        make_heap(f.begin(),f.end(), greaters());
        bool noANS=false;

        fr(0,n,i){
            if(b[i]>a[i]){
                noANS=true;
                break;
            }
            if(f.empty()){
                if(a[i]!=b[i]){
                    f.pb(b[i]);
                    push_heap(f.begin(),f.end(),greaters());
                }
            }else{
               while(true){
                   int top = f.front();
                   if(top<b[i]){
                       ans.pb(top);
                       pop_heap(f.begin(),f.end(),greaters());
                       f.pop_back();
                   }else{
                       if(top!=b[i] && a[i]!=b[i]){
                           f.pb(b[i]);
                           push_heap(f.begin(),f.end(),greaters());
                       }
                       break;
                   }
                   if (f.empty()){
                       if(a[i]!=b[i]){
                           f.pb(b[i]);
                           push_heap(f.begin(),f.end(),greaters());
                       }
                       break;
                   }
               }
            }
        }

        fr(0,f.size(),i){
            ans.pb(f[i]);
        }

        map<int,int> r;
        fr(0,ans.size(),i){
            r[ans[i]]++;
        }

        fr(0,m,j){
            r[c[j]]--;
        }

        for(auto p: r){
            if(p.second>0){
                noANS=true;
            }
        }

        if(noANS){
            cout << "NO"<< '\n' ;
        }else{
            cout << "YES"<< '\n' ;
        }

    }

    return 0;
}