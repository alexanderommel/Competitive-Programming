#include <bits/stdc++.h>
#define frs(siz, init, j) for (int j=init; j<siz; j++)
#define ll long long
using namespace std;

const int MAX_N = 2e5 + 10;
vector<int> tree[MAX_N];
int l[MAX_N];
int r[MAX_N];
int ans=0;

ll sol(int tree_indx){
    ll children_sum=0;
    for(int u: tree[tree_indx]){
        children_sum+=sol(u);
    }
    if (children_sum< (ll) l[tree_indx]){
        ++ans;
        return r[tree_indx];
    }
    return min((ll) r[tree_indx],children_sum);
}

int main(){

    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        frs(n+1,2,i){
            int parent_i;
            cin >> parent_i;
            tree[parent_i].push_back(i);
        }
        frs(n+1,1,h){
            cin >> l[h] >> r[h];
        }
        ans=0;
        sol(1);
        cout << ans << endl;
        frs(n+1,1,j){
            tree[j].clear();
        }

    }
}