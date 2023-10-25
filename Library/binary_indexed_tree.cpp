#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxN = 2e5;

int N, Q;
ll A[maxN+1], BIT[maxN+1];

void update(int idx, ll new_val){
    ll diff = new_val - A[idx];
    for(int i = idx; i <= N; i += -i&i)
        BIT[i] += diff;
    A[idx] = new_val;
}

void range_update(int R, int L, ll new_val){
    update(R+1,-new_val);
    update(L,new_val);
}

ll query(int idx){
    ll sum = 0;
    for(int i = idx; i > 0; i -= -i&i)
        sum += BIT[i];
    return sum;
}

ll range_query(int R, int L){
    return query(R)- query(L-1);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> Q;
    for (int i = 1; i <= N; ++i) {
        cin >> A[0];
        update(i,A[0]);
    }
    while(Q--){
        int type; cin >> type;
        if (type==1){
            int ix; cin >> ix;
            ll new_value; cin >> new_value;
            update(ix,new_value);
        }else{
            int left,right; cin >> left >> right;
            cout << range_query(right,left)<<'\n';
        }
    }
}