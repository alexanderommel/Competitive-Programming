#include <bits/stdc++.h>
#define pb push_back
#define vi vector<int>
#define ll long long

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
    int n,k;
    cin >> n >> k;
    int ans = n;
    for(int i=1;i<=n;i++){
    int a=(i+k-2)/k;
    int b=(n-i+k-1)/k;
    ans = min(ans,a+b);
    }
    cout << ans+1<< '\n';
    }
    return 0;
}