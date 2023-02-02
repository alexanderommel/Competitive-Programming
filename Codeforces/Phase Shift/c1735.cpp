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

bool used[27];
const int N= 66;
vector<int> parent, sz;
int already[27];

void init(){
    parent = vector<int>(N,0);
    sz = vector<int>(N,0);
    for(int i=1;i <N; i++){
        parent[i]=i;
        sz[i]=1;
    }
}

int find_representative(int e){
    while(e!=parent[e]){parent[e]=parent[parent[e]]; e = parent[e];}return e;
}
void union_set(int u,int v){
    int a = find_representative(u); int b = find_representative(v);
    if(a==b){ return; }
    if(sz[a]>sz[b]){swap(a,b);}
    sz[b]+=sz[a];
    sz[a]=0;
    parent[a]=parent[b];
}


int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while(t--){

        int n;
        cin >> n;
        string t;
        cin >> t;

        int z=1;
        string s;
        int ans[n];

        init();

        fr(0,27,i){
            used[i]=false;
            already[i]=-1;
        }

        fr(0,n,i) {
            z=1;
            int letra = t[i] - 'a' + 1;
            int rep = find_representative(letra);
            if (already[letra]!=-1){
                ans[i]=already[letra];
            }else{
                while(find_representative(z)==rep && z<27 || used[z] && z<27){
                    z++;
                }

                if (z>26){
                    fr(1,27,xx){
                        if (used[xx]==false){
                            z = xx;
                            break;
                        }
                    }
                }

                union_set(letra,z);
                already[letra]=z;
                used[z]=true;
                ans[i]=z;
            }

        }


        fr(0,n,i){
            char letra = ans[i]+'a' - 1;
            cout << letra << "";
        }
        cout << '\n';

    }

    return 0;
}
