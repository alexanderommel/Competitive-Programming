#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 3 + (1e6);
const int Ke= 2+ (1e6);
ll prepp[N];
const int LM=36;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        int color_inicial =-1;
        int color_final =-1;
        ll fa=0;
        ll fb=0;
        int ans[n];
        for (int i = 0; i < n; ++i) {
            int nm;
            cin >> nm;
            ans[i]=nm;
            if (i==0){
                color_inicial = nm;
            }
            if (i==n-1){
                color_final = nm;
            }
        }
        int cd=0;
        for (int i = 0; i < n; ++i) {
            if (ans[i]==color_inicial)fa++;
            if (fa==k){
                cd = i+1;
                break;
            }
        }
        for (int i = cd; i < n; ++i) {
            if (ans[i]==color_final)fb++;
        }
        if (color_inicial==color_final){
            if (fa>=k){
                cout << "YES\n";
            }else{
                cout << "NO\n";
            }
        }else{
            if (fa>=k && fb>=k){
                cout << "YES\n";
            }else{
                cout << "NO\n";
            }
        }
    }
}