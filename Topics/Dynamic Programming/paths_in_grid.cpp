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
* Find a path from the upper-left corner to the lower-right corner
 * of an n x n grid, with the restriction that we may only move down
 * and right. Each square contains an integer, and the path should be
 * constructed so that the sum of the values alog the path is as
 * large as possible.
*/

/**
*
*/

int main(){

    int N=5;
    int grid[5][5]={{3,7,9,2,7},
                    {9,8,3,5,5},
                    {1,7,9,8,5},
                    {3,8,6,4,10},
                    {6,3,9,7,8}};

    int values[N][N];
    fr(0,N,r){
        fr(0,N,c){
            int sum = grid[r][c];
            int a=0,b=0;
            if (r-1>=0){
                a = values[r-1][c];
            }
            if(c-1>=0){
                b = values[r][c-1];
            }
            sum = max(a,b)+sum;
            values[r][c]=sum;
        }
    }
    cout << values[N-1][N-1] << '\n';

    return 0;
}