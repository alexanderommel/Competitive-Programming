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
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string pins[n];
        //map<string,int> f;
        fr(0,n,i){
            cin >> pins[i];
            //f[pins[i]]++;
        }
        int changed=0;
        fr(0,n,j){
            int repeated = 0;
            fr(0,n,c){
                if (pins[c]==pins[j]){
                    repeated++;
                }
            }
            if (repeated==1){
                continue;
            }
            changed++;
            fr(0,10,k){
                string nuevo = pins[j];
                nuevo = to_string(k) + nuevo[1] + nuevo[2] + nuevo[3];
                bool passes = true;
                fr(0,n,c){
                    if (c==j){
                        continue;
                    }
                    if (nuevo==pins[c]){
                        passes = false;
                        break;
                    }
                }
                if (passes){
                    pins[j]=nuevo;
                    break;
                }
            }
        }

        cout << changed << '\n';
        fr(0,n,z){
            cout << pins[z] << '\n';
        }
    }

    return 0;
}
