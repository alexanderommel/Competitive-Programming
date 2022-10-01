#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define fr(size, i) for (int i=0; i<size; i++)
#define frs(size,start,i) for (int i=start; i<size; i++)
#define ll long long
#define pii pair<int, int>
#define vpii vector<pii>
#define len(arr) arr.size()
#define vs vector<string>
#define pb push_back
using namespace std;

void solucion(vs S , string t){
    vpii ans;
    int p1=0;
    int k = p1;
    while(k!=len(t)){
        string best1, best2;
        int pos1=0, pos2=k;
        int i1=-1,i2=-1;
        frs(k,p1,i){
            frs(len(t),k,j){
                fr(len(S),m){
                    if ((S[m]==t.substr(i,j-i+1)) && (len(S[m])+1)>len(best1)){
                        best1 = S[m];
                        pos1 = i;
                        i1 = m;
                    }
                }
            }

        }
        frs(len(t),k,i){
            fr(len(S),l){
                if (S[l]==t.substr(k,i-k+1)){
                    best2 = S[l];
                    i2=l;
                }
            }
        }
        if (best1.empty() && best2.empty()){
            cout << -1 << endl;
            return;
        }
        k = pos2 + len(best2);
        int position_in_string = pos2;
        int set_index = i2;
        if ((pos1+len(best1))>(pos2+len(best2))){
            k = pos1 + len(best1);
            position_in_string = pos1;
            set_index = i1;
        }
        ans.pb({set_index,position_in_string});
        p1++;
    }
    cout << ans.size() << endl;
    fr(ans.size(),i){
        cout << ans[i].first + 1 << " " << ans[i].second + 1 << endl;
    }
}

int main() {
    int q=0;
    cin >> q;
    while (q--){
        string t;
        int n;
        cin >> t;
        cin >> n;
        vs S(n);
        for (auto &d : S) cin >> d;
        solucion(S,t);
    }
    return 0;
}