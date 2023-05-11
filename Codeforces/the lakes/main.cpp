#include <bits/stdc++.h>
#define pb push_back
#define vi vector<int>
#define ll long long
#define vll vector<long long>
#define pll pair<ll,ll>
using namespace std;
typedef std::tuple<int,int,int> mytuple;

vector<int> parent, sz, answer;

void init(int N){
    parent = vector<int>(N,0);
    sz = vector<int>(N,0);
    answer = vector<int>(N,0);
    for(int i=1;i <N; i++){
        parent[i]=i;
        sz[i]=1;
        answer[i]=0;
    }
}

int find_representative(int e){
    while(e!=parent[e]){parent[e]=parent[parent[e]]; e = parent[e];}return e;
}
void union_set(int u,int v, int new_value){

    int a = find_representative(u); int b = find_representative(v);
    if(a==b){
        return;
    }
    if(sz[a]>sz[b]){swap(a,b);}
    sz[b]+=sz[a];
    answer[b]+=answer[a];
    answer[a]=0;
    sz[a]=0;
    parent[a]=parent[b];
}



int main(){
    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >>m;
        int A[n+1][m+1];
        init((n*m) + 10);

        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                A[i][j]=0;
            }
        }


        for(int i=1;i<=n;i++){
            int step = m * (i-1);
            for(int j=1;j<=m;j++){
                cin >> A[i][j];
                answer[step+j]=A[i][j];
                //cout << step+j<<": "<<answer[step+j]<<'\n';
                if(A[i][j]==0){
                    sz[step+j]=0;
                    continue;
                }
                if(A[i-1][j]>0){
                    union_set((m*(i-1)) + j,(m*(i-2)) + j,A[i][j]);
                }
                if(A[i][j-1]>0){
                    union_set((m*(i-1)) + j,(m*(i-1)) + j - 1,A[i][j]);
                }
            }
        }
        int ans=0;
        for(int i=0;i<answer.size();i++){
            ans = max(ans,answer[i]);
        }
        cout << ans <<'\n';
    }
}