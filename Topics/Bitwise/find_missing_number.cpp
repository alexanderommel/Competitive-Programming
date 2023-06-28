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

/**
 * Given an array arr[] of size N-1 with integers in the range of [1, N], the task is to find the missing number from the first N integers.
**/

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int nums[] = {1,2,3,5};
    int n = 5;

    /**
     * The operator XOR returns 0 for each pair of bits that
     * are equal, so if a=b, then XOR(a,b)=0
     *
     * Let a1 XOR a2 XOR a3 XOR a4 = a
     * And a1 XOR ... XOR a5 = b.
     * Then a XOR b = (a1 XOR a2 XOR ... XOR a4) XOR (a1 XOR a2 XOR ... XOR a5)
     * equals to = a1 XOR a1 XOR a2 XOR a2 ... XOR a5 = 0 XOR  a5 = a5 which is the missing number
     *
     * **/

    int a = 0;
    fr(1,n+1,i){
        a^= i;
    }

    int b = nums[0];
    fr(1,n-1,i){
        b^=nums[i];
    }

    int ans = (a^b);

    cout << ans << "\n";

    return 0;
}


