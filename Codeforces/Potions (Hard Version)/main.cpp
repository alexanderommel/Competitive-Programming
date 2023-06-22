#include <bits/stdc++.h>
#define pb push_back
#define vi vector<int>
#define ll long long
#define vll vector<long long>
#define pll pair<ll,ll>
#define fr(s,n,i) for (long long i=s; i<n; ++i)
#define fri(s,e,i) for (long long i=s; i>=e; --i)
#define len(arr) arr.size()
using namespace std;
typedef std::tuple<int,int,int> mytuple;




#include <bits/stdc++.h>
#define pb push_back
#define vi vector<int>
#define ll long long


int main(){
    int n;
    cin >> n;
    int ans=0;
    priority_queue <ll, vector<ll>, greater<ll>> pq;
    ll sum=0;
    for (int i = 0; i < n; ++i) {
        ll nm;
        cin >> nm;
        if (nm>=0){
            sum+=nm;
            ans++;
        }else{
            sum+=nm;
            ans++;
            pq.push(nm);
            while(sum<0 && !pq.empty()){
                sum-=pq.top();
                pq.pop();
                ans--;
            }
        }
    }
    cout << ans <<'\n';

}