#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(s,n,i) for (long long i=s; i<n; ++i)
#define pb push_back
#define fri(s,e,i) for (long long i=s; i>=e; --i)

int main(){

    int t;
    cin >> t;
    while(t--)  {
        int n;
        cin >> n;
        int a[n];
        int b[n];
        fr(0,n,i){
            cin >> a[i];
        }
        fr(0,n,i){
            cin >> b[i];
        }
        int last_end = -1;
        fr(0,n,i){
            if(a[i]>last_end){
                cout << b[i]-a[i]<<" ";
                last_end = b[i];
            }else{
                cout << b[i]-last_end<<" ";
                last_end = b[i];
            }
        }
        cout <<'\n';
    }

}