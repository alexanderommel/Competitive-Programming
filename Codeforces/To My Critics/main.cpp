#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 3 + (1e6);
const int Ke= 2+ (1e6);
ll prepp[N];

int main(){
    int t;
    cin >> t;
    while(t--){
        int r=12;
        int a,b,c;
        cin >> a >> b >> c;
        r+=a;
        r+=b;
        a+=r;
        a-=r;
        vector<int> ans;
        ans.push_back(a);
        ans.push_back(b);
        ans.push_back(c);
        std::sort(ans.begin(), ans.end());
        if (ans[2]+ans[1]>9){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
}
