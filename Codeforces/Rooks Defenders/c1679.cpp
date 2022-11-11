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

void update(int *BIT,int index, int value, int n){
    int k = index;
    while(k<=n){
        BIT[k]+=value;
        k += k&-k;
    }
}

int sum(int *BIT, int index){
    if (index==0){
        return 0;
    }
    int k = index;
    int ans = 0;
    while(k>0){
        ans+=BIT[k];
        k -= k&-k;
    }
    return ans;
}

int *buildBIT(int n){
    int *BIT = new int[n+1];
    fr(1,n+1,i){
        BIT[i]=0;
    }
    return BIT;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n,q;
    cin >> n >> q;

    int A[n+1];
    int B[n+1];
    fr(0,n+1,i){
        A[i]=0;
        B[i]=0;
    }
    int *BIT_C = buildBIT(n);
    int *BIT_R = buildBIT(n);

    while(q--){
        int t;
        cin >> t;
        if (t==1){
            int x,y;
            cin >> x >> y;
            A[x]++;
            B[y]++;
            if (A[x]==1){
                update(BIT_R,x,1,n);
            }
            if(B[y]==1){
                update(BIT_C,y,1,n);
            }
        }
        if(t==2){
            int x,y;
            cin >> x >> y;
            A[x]--;
            B[y]--;
            if (A[x]==0){
                update(BIT_R,x,-1,n);
            }
            if(B[y]==0){
                update(BIT_C,y,-1,n);
            }
        }
        if(t==3){
            int x1,y1,x2,y2;
            cin >> x1 >> y1 >> x2 >> y2;
            int sum_x = sum(BIT_R,x2) - sum(BIT_R,x1-1);
            int sum_y = sum(BIT_C,y2) - sum(BIT_C,y1-1);
            if (sum_x==(x2-x1+1) || sum_y==(y2-y1+1)){
                cout << "Yes" << '\n';
            }else{
                cout << "No" << '\n';
            }
        }
    }

    return 0;
}
