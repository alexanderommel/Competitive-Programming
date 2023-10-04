#include<bits/stdc++.h>
using namespace std;

#define ll long long

struct FenwickTree {
    vector<int> bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> const &a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    // inclusive interval
    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

int main(){
    int N = 100;
    FenwickTree bit = FenwickTree(N);
    vector<int> a(N);
    for (int i = 0; i < N; ++i) a[i]=i+1, bit.add(i,a[i]);
    cout << "-------------------- Queries ----------------------\n";
    int Q; cin >> Q;
    while(Q--){
        int l,r; cin >> l >> r;
        cout << bit.sum(l,r) <<'\n';
    }
}