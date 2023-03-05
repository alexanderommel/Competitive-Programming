#include<bits/stdc++.h>
using namespace std;
#define ll long long
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
    while(t--)  {
        int n;
        cin >> n;
        ll* bit = buildBIT(n);
        ll extra[n+1];
        extra[0]=0;
        ll S[n+1];
        S[0]=0;
        ll a[n+1];
        fr(0,n,i){
            cin >> a[i+1];
        }
        fr(1,n+1,i){
            extra[i]=0;
            ll nm;
            cin >> nm;
            S[i] = S[i-1] + nm;
        }
        fr(1,n+1,i){
            int l=0;
            int r=n;
            ll current = S[i-1] + a[i];
            int x;
            while(l<=r){
                x = (l+r)/2;
                if(S[x]>current)    {
                    r = x-1;
                }else{
                    l = x+1;
                }
            }
            //cout << "found index: "<<r<<" for number: "<<a[i]<<'\n';
            if(r<n){
                extra[r+1]+=abs(current-S[r]);
                //cout << "increase index "<<r+1<<" by:"<<abs(current-S[r])<<'\n';
            }

            if(r>=i){
                //cout << "increasing index "<<i<<" by one\n";
                //cout << "decreasing index "<<r+1<<" by one\n";
                update(bit,i,1,n);
                if(r<n){
                    update(bit,r+1,-1,n);
                }
            }
        }
        fr(1,n+1,i){
            ll cc = sum(bit,i);
            extra[i]+=(cc*(S[i]-S[i-1]));
            cout << extra[i]<< " ";
        }
        //printBIT(bit,n);
        cout <<'\n';
    }
}