#include <bits/stdc++.h>
#define pb push_back
#define vi vector<int>
#define ff(size) for (int i = 0; i < size; i++)
#define viin(vec,n) ff(n){int x; cin>>x; vec.pb(x);}
#define ll long long
#define fr(size, i) for (int i=0; i<size; i++)
using namespace std;


int main(){
    int n,m;
    cin >> n >> m;
    vi a;
    ff(n){
        int ai;
        cin >> ai;
        a.pb(ai);
    }

    std::sort(a.begin(), a.end(), greater<>() );
    int fsl=0;
    int remain = m;
    fr(n,i){
        remain = remain - a[i];
        fsl++;
        if (remain<=0){
            cout << fsl << endl;
            break;
        }
    }

}