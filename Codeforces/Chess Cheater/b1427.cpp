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

        int n,k;
        cin >> n >> k;
        string s;
        cin >> s;

        int ls=0,ws=0;

        fr(0,n,i){
            if(s[i]=='L'){
                ls++;
            }else{
                ws++;
            }
        }

        if (ls==n){
            cout << max(2*k - 1,0) << '\n';
            continue;
        }

        if(ls==0){
            cout << 2*n - 1 << '\n';
            continue;
        }

        int lp,rp;
        int lsl=0,lsr=0;
        fr(0,n,i){
            if(s[i]=='W'){
                lp=i;
                break;
            }else{
                lsl++;
            }
        }

        fri(n-1,0,i){
            if(s[i]=='W'){
                rp = i + 1;
                break;
            }else{
                lsr++;
            }
        }

        vi c;
        int local=0;
        int ans=0;
        bool w_before=false;
        fr(lp,rp,i){
            if(s[i]=='W'){
                if (local!=0){
                    c.pb(local);
                    local=0;
                    w_before=false;
                }
                if (w_before){
                    ans+=2;
                }else{
                    w_before=true;
                    ans+=1;
                }
            }else{
                w_before=false;
                local++;
            }
        }

        //cout << "current ans: " << ans << '\n';

        std::sort(c.begin(), c.end());
        fr(0,c.size(),i){
            if(c[i]<=k){
                ans+=( 2*c[i] + 1);
                k-=c[i];
            }else{
                ans+=(2*k);
                k=0;
                break;
            }
        }

        //cout << "current ans 2: " << ans << '\n';

        if(lsr<=k){
            ans+=(2*lsr);
            k-=lsr;
        }else{
            ans+=(2*k);
            k=0;
        }

        //cout << "current ans 3: " << ans << '\n';

        if(k==0){
            cout << ans << '\n';
            continue;
        }

        if(lsl<=k){
            ans+=(2*lsl);
            k-=lsl;
        }else{
            ans+=(2*k);
            k=0;
        }

        cout << ans << '\n';

    }
    return 0;
}