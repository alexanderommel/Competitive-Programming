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

void update(ll* BIT, ll index, ll value, int n){
    ll k = index;
    while(k<=n){
        BIT[k]+=value;
        k += k&-k;
    }
}

ll sum(ll* BIT, ll index){
    if (index<=0){
        return 0;
    }
    ll k = index;
    ll ans = 0;
    while(k>0){
        ans+=BIT[k];
        k -= k&-k;
    }
    if(ans>3){
        ans = 3;
    }
    if(ans<0){
        ans=0;
    }
    return ans;
}

ll* buildBIT(int n){
    ll* BIT = new long long [n+1];
    fr(1,n+1,i){
        BIT[i]=0;
    }
    return BIT;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n,q;
        cin >> n >> q;
        ll m[n][4];
        ll* BIT = buildBIT(n+1);
        fr(0,n,i){
            ll num;
            cin >> num;
            m[i][0]=num;
            fr(1,4,j){
                ll ans=0;
                string digits = to_string(num);
                fr(0, digits.size(),z){
                    ans+=digits[z]-'0';
                }
                num = ans;
                m[i][j]=ans;
            }
        }
        fr(0,q,i){
            ll type;
            cin >> type;
            if(type==1){
                ll l,r;
                cin >> l >> r;
                update(BIT,l,1,n);
                //cout << "sum for index l: " <<l<<"  is: "<<sum(BIT,l)<<'\n';
                update(BIT,r+1,-1,n);
                //cout << "sum for index r: " <<r<<"  is: "<<sum(BIT,r)<<'\n';

            }else{
                ll index;
                cin >> index;
                ll app = sum(BIT,index);
                cout << m[index-1][app]<<'\n';
            }
        }

    }
    return 0;
}