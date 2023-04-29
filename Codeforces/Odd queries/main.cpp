#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define fr(s,n,i) for (long long i=s; i<n; ++i)

void update(ll *BIT,int index, ll value, int n){
    int k = index;
    while(k<=n){
        BIT[k]+=value;
        k += k&-k;
    }
}

ll sum(ll *BIT, int index){
    if (index==0){
        return 0;
    }
    int k = index;
    ll ans = 0;
    while(k>0){
        ans+=BIT[k];
        k -= k&-k;
    }
    return ans;
}

ll *buildBIT(int n){
    ll *BIT = new ll[n+1];
    for(int i=1; i<=n; ++i){
        BIT[i]=0;
    }
    return BIT;
}

void printBIT(ll *BIT, int n){
    cout << "BIT\n";
    for(int i=1;i<=n;++i){
        cout << sum(BIT,i) << " ";
    }
    cout << '\n';
}


int main(){
    int t;
    cin >> t;
    while(t--){
        ll n,q;
        cin >> n >> q;
        ll S[n+1];
        S[0]=0;
        for(int i=1; i<=n;i++){
            ll a;
            cin >> a;
            S[i]=S[i-1]+a;
        }
        for(int j=0;j<q;j++){
            int l,r,k;
            cin >> l >>r >> k;
            bool query_even = true;
            if(((r-l+1)*k)%2!=0){
                query_even = false;
            }
            bool even=true;
            ll diff = S[n]-(S[r]-S[l-1]);
            if(diff%2!=0){
                even=false;
            }
            if((even==true && query_even!=true) || (even!=true && query_even==true)){
                cout << "YES\n";
            }else{
                cout << "NO\n";
            }
        }
    };
}