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

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        vi a;
        viin(a,n);

        int i = n-1;
        int p= -99;
        int ans=0;
        while(i>=-1){
            if (i==-1){
                if (s[0]=='1'){
                    int rel_ans = 0;
                    fr(0,p+1,j){
                        rel_ans+=a[j];
                    }
                    ans+=rel_ans;
                }
                break;
            }
            if(s[i]=='0'){
                if (p!=-99){
                    std::sort(a.begin()+i, a.begin()+p+1,greater<>());
                    int rel_ans=0;
                    fr(i,p,j){
                        rel_ans+=a[j];
                    }
                    ans+=rel_ans;
                    p=-99;
                }
            }else{
                if (p==-99){
                    p=i;
                }
            }
            i--;
        }

        cout << ans << '\n';

    }

    return 0;
}
