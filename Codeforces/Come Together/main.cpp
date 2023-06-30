#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int NNN= 101;

vector<int> adj[NNN];
vector<map<int,int>> ans(NNN);
bool mem[NNN];

int main(){
    int t;
    cin >> t;
    while(t--){
        ll a1,a2;
        cin >> a1 >> a2;
        ll b1,b2;
        cin >> b1 >> b2;
        ll c1,c2;
        cin >> c1 >> c2;
        ll ans=1;
        ll vab = abs(b2-a2);
        ll vac = abs(c2-a2);
        ll hba = abs(a1-b1);
        ll hca = abs(a1-c1);
        if((a2>c2 && a2 >b2) || (a2<c2 && a2<b2)) ans+=min(vab,vac);
        if ((b1 > a1 && c1 > a1) || (a1>c1 && a1>b1)) ans+=min(hba,hca);
        cout << ans <<'\n';
    }
}