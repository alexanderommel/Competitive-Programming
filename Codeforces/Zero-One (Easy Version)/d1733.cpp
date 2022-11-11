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



int main(){
    int t=0;
    cin >> t;
    while (t--){

        int n,x,y;
        cin >> n >> x >> y;
        string as,bs;
        cin >> as;
        cin >> bs;

        if (as==bs){
            cout << 0 <<'\n';
            continue;
        }

        string d = "";

        fr(0,n,c){
            if (as[c]==bs[c]){
                d+="0";
            }else{
                d+="1";
            }
        }

        //cout << "binary: " << d <<'\n';

        int num_ones = 0;
        int first_pos = -1;
        fr(0,n,j){
            if (d[j]=='1'){
                num_ones++;
                if(first_pos==-1){
                    first_pos = j;
                }
            }
        }

        if((num_ones%2)!=0){
            cout << -1 << '\n';
            continue;
        }

        if (num_ones>2){
            ll ans = num_ones / 2;
            ans*=y;
            cout << ans  << '\n';
        }else{
            if (d[first_pos]!=d[first_pos+1]){
                cout << y << '\n';
                continue;
            }
            if (n>=5){
                cout << min(x,2*y) << '\n';
            }else{
                cout << x << '\n';
            }
        }

    }
    return 0;
}
