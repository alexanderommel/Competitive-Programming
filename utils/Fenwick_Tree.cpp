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