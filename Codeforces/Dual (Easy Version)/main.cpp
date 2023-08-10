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
        int n;
        cin >> n;
        vector<int> negs;
        int a[n];
        negs.push_back(-1);
        for (int i = 0; i < n; ++i) {
             cin >> a[i];
            if (a[i]<0){
                negs.push_back(i);
            }
        }
        if (negs.size()==1){
            cout <<n-1 <<'\n';
            for (int i = 1; i <= n-1; ++i) {
                cout <<  i + 1 << " " <<i << '\n';
            }
        }else{
            for(int i: negs){
                int test[n];
                if (i>=0){
                    test[i]=a[i];
                }
                int ops=0;
                vector<pair<int,int>> ans;
                if (i<n-1){
                    test[i+1]=a[i+1];
                }
                for (int j = i+2; j < n ; ++j) {
                    if (a[j]>=0){
                        ops++;
                        test[j]=a[j]+test[j-1];
                        ans.emplace_back(j,j-1);
                    }else{
                        ops+=2;
                        test[j]=a[j]+test[j-1];
                        test[j]=test[j]+test[j-1];
                        ans.emplace_back(j,j-1);
                        ans.emplace_back(j,j-1);
                    }
                }
                for (int j = i-1; j >=0 ; --j) {
                    if (a[j]<=0){
                        ops++;
                        test[j]=a[j]+test[j+1];
                        ans.emplace_back(j,j+1);
                    }else{
                        ops+=2;
                        test[j]=a[j]+test[j+1];
                        test[j]=test[j]+test[j+1];
                        ans.emplace_back(j,j+1);
                        ans.emplace_back(j,j+1);
                    }
                    //cout << test[j ]<<'\n';
                }
                //cout <<"eval\n";
                int lst = test[0];
                bool ok=true;
                for (int j = 1; j < n; ++j) {
                    if (test[j]<lst){
                        ok=false;
                        break;
                    }
                    lst=test[j];
                }
                if (ok){
                    cout  << ops <<'\n';
                    for(auto pp: ans){
                        cout << pp.first +1<< " " << pp.second+1 <<'\n';
                    }
                    break;
                }
            }
        }
    }
}