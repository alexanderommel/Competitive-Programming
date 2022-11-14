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
        int n,m;
        cin >> n >> m;

        int ca=-10,cb=-10;
        ll diff=0;
        int matrix[n][m];

        fr(0,n,i){

            vll a;

            fr(0,m,j){
                ll value;
                cin >> value;
                matrix[i][j]=value;
                a.pb(value);
            }

            if (diff>=3){
                continue;
            }

            vll b = a;
            std::sort(a.begin(), a.end());

            if (ca>=0){
                ll temp = b[ca];
                b[ca] = b[cb];
                b[cb] = temp;
            }

            fr(0,m,j){

                if (diff>=3){
                    continue;
                }

                if (a[j]!=b[j]){
                    diff++;
                    if (diff==1){
                        if (ca==-10){
                            ca=j;
                        }
                    }
                    if(diff==2){
                        if (cb==-10){
                            cb=j;
                        }
                    }
                }
            }

        }

        bool good=true;
        if (diff<3 && ca>=0){
            fr(0,n,zz){

                ll temp = matrix[zz][ca];
                matrix[zz][ca] = matrix[zz][cb];
                matrix[zz][cb] = temp;

                int less = -1;

                if (!good){
                    break;
                }

                fr(0,m,xx){
                    if (matrix[zz][xx]<less){
                        good = false;
                        break;
                    }
                    less = matrix[zz][xx];
                }
            }
        }

        if (!good){
            cout << -1 <<'\n';
            continue;
        }

        if (diff>=3){
            cout << -1 << '\n';
            continue;
        }
        if (diff==2){
            cout << ca + 1 << " " << cb + 1<< '\n';
            continue;
        }
        if (diff==0){
            cout << 1 << " " << 1 << '\n';
            continue;
        }

    }

    return 0;
}
