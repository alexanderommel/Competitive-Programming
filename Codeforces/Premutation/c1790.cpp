#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(s,n,i) for (long long i=s; i<n; ++i)
#define pb push_back
#define fri(s,e,i) for (long long i=s; i>=e; --i)

int main(){

    int t;
    cin >> t;
    while(t-- ){
        int n;
        cin >> n;
        int A[n][n-1];
        map<int,map<int,int>> M;
        fr(0,n,i){
            fr(0,n-1,j){
                cin >> A[i][j];
                M[j][A[i][j]]++;
            }
        }
        pair<int,int> ans={-1,-1};
        vector<int> anss;
        for(auto pp: M){
            vector<pair<int,int>> res;
            for(auto par: pp.second){
                res.emplace_back(par);
            }
            pair<int,int> aa = res[0];
            pair<int,int> bb = res[1];
            if(ans.first==-1){
                if(aa.second>bb.second){
                    anss.push_back(aa.first);
                    ans = bb;
                }else{
                    anss.push_back(bb.first);
                    ans = aa;
                }

            }else{
                if(aa.first==ans.first){
                    anss.push_back(aa.first);
                    ans = bb;
                }else{
                    anss.push_back(bb.first);
                    ans = aa;
                }
            }
        }
        anss.push_back(ans.first);
        fr(0,n,i){
            cout << anss[i]<<" ";
        }
        cout << '\n';
    }


}