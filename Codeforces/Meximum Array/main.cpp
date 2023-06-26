#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll L=1;
const ll R = 1e13 +1;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        map<int,int> mx;
        int a[n];
        priority_queue <int, vector<int>, greater<int>> pq;
        for (int i = 0; i < n+2; ++i) {
            mx[i]=0;
        }
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            mx[a[i]]++;
        }
        for (int i = 0; i < n+2; ++i) {
            if(mx[i]==0){
                pq.push(i);
                break;
            }
        }
        int r=0;
        vector<int> b;
        while(r<n){
            int mex = pq.top();
            //cout << "test mex: "<<mex<<'\n';
            if (mex==0){
                b.push_back(0);
                r++;
                continue;
            }
            int srch=0;
            int p=r;
            map<int,int> mym;
            for (; p < n; ++p) {
                //cout << "looking for: "<<srch<<'\n';
                if (mym.count(a[p])==0 && a[p]<mex){
                    srch++;
                    mym[a[p]]=1;
                }
                mx[a[p]]--;
                if (mx[a[p]]==0){
                    pq.push(a[p]);
                }
                if (srch==mex){
                    //cout << "mex found on index: "<<p<<'\n';
                    break;
                }
            }
            r=p+1;
            b.push_back(mex);
        }
        cout << b.size()<<'\n';
        for (int i = 0; i < b.size(); ++i) {
            cout << b[i] << " ";
        }
        cout <<'\n';
    }
}