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
 * Given an array of n integers, find the maximum-length sequence
 * of array elements that goes from left to right, and each element
 * in the sequence is larger than de previous element.
 *
 */

int main(){
    //int a[9]={999,6,2,5,1,7,4,8,3};
    //int a[9]={ 9999,10, 22, 9, 33, 21, 50, 41, 60 };
    int a[10]={999,10, 22, 9, 33, 21, 50, 41, 60, 80};
    int n=9;
    int values[n+1];
    int higher[n+1];
    int maxx = 0;
    higher[0]=INFINITY;
    values[0]=0;
    fr(1,10,x){
        values[x]=1;
        if (a[x]<=a[maxx]){
            if (values[x]>=values[maxx]){
                maxx = x;
            }
        }else{
            values[x]=values[maxx]+1;
            maxx = x;
        }
    }
    int ans=-1;
    fr(0,n+1,i){
        ans = max(ans,values[i]);
    }
    cout << ans << '\n';
    return 0;
}
