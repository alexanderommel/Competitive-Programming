#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int NNN= 101;

vector<int> adj[NNN];
vector<map<int,int>> ans(NNN);
bool mem[NNN];


void dfs(int node, int i){
    if (mem[node]) return;
    mem[node]=true;
    for(auto s: adj[node]){
        ans[s][i]++;
        dfs(s,i);
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        ll n;
        float d,h;
        cin >> n >> d >> h;
        auto a = (float)((float)(d*h)/2);
        float ans=0;
        float last=-1;
        float tanh = (h/(d/2));
        for (int i = 0; i < n; ++i) {
            float y;
            cin >> y;
            if (i==0){
                ans+=a;
                last = y +h;
            }else{
                if (y<last){
                    //cout << "jump with num: "<<y<<'\n';
                    float new_h = abs(y-last);
                    float new_d = new_h/tanh;
                    new_d = 2* new_d;
                    //cout << "d: "<<new_d << " h: "<<new_h<<'\n';
                    float m_a = (new_d*new_h)/2;
                    ans-=m_a;
                }
                last = y + h;
                ans+=a;
            }
        }
        cout << ans <<'\n';
    }
}