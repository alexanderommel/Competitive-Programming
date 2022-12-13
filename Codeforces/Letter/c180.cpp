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

vector<pair<int,int>> M;
int lowest=0;

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string s;
    cin >> s;

    int n = s.size();

    int ans = INT_MAX;

    int lp=-1,rp=-1;

    fr(0,n,i){
        if (s[i]>='a'){
            lp=i;
            break;
        }
    }

    fri(n-1,0,i){
        if (s[i]<'a'){
            rp=i;
            break;
        }
    }

    if (lp==-1 || rp==-1){
        cout << 0 << '\n';
        return 0;
    }

    int u=0,l=0;

    cout << "GO" <<'\n';

    fr(lp,rp+1,i){
        if (s[i]<'a'){
            cout << s[i] << " ";
            u++;
        }else{
            l++;
        }
    }



    cout << "GO" <<'\n';

    cout << min(u,l) << '\n';
    return 0;

}
