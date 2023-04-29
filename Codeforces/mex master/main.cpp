#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define fr(s,n,i) for (long long i=s; i<n; ++i)
bool comparador_descendente_normal ( const long long int& l, const long long int& r){ return l > r; }

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<ll> a;
        int zeros=0;
        for(int i=0;i<n;i++)    {
            ll ai;
            cin >> ai;
            if(ai==0){
                zeros++;
            }else{
                a.push_back(ai);
            }
        }
        std::sort(a.begin(), a.end());
        if(zeros<=a.size()+1){
            cout << 0 <<'\n';
            continue;
        }else{
            if(a.size()==0){
                cout << 1 <<'\n';
                continue;
            }
            if(a.size()==1){
                if(a[0]==1){
                    cout << 2 <<'\n';
                    continue;
                }else{
                    cout << 1 <<'\n';
                    continue;
                }
            }else{
                ll left = a[0];
                ll right = a[a.size()-1];
                if (left==1 && right==1){
                    cout << 2 <<'\n';
                    continue;
                }else{
                    cout << 1 << '\n';
                    continue;
                }
            }
        }


    }
}