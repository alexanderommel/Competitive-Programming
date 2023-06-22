#include <bits/stdc++.h>
#define pb push_back
#define vi vector<int>
#define ll long long
#define vll vector<long long>
#define pll pair<ll,ll>
using namespace std;
typedef std::tuple<int,int,int> mytuple;


#include <bits/stdc++.h>
#define pb push_back
#define vi vector<int>
#define ll long long

using namespace std;

int gcd(int a, int b){
    if (a<b){
        swap(a,b);
    }
    if(b==0)
        return a;
    return gcd(b,a%b);
}

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<pair<int,int>> a(1001);
        for(int i=0;i<=1000;i++ ){
            a[i]={-1,-1};
        }
        for(int i=1;i<=n;i++ ){
            int nm;
            cin >> nm;
            if(a[nm].first==-1){
                a[nm]={i,-1};
            }else{
                a[nm]={a[nm].first,i};
            }
        }
        int ans=-1;
        for(int i=1;i<=1000;i++){
            for(int j=i; j<=1000;j++){
                int g  = gcd(i,j);
                if(g==1){
                    if(a[i].first!=-1 && a[j].first!=-1){
                        ans = max(ans,min(a[i].first,a[j].first)+max(a[i].first,a[j].first));
                    }
                    if(a[i].second!=-1 && a[j].first!=-1){
                        ans = max(ans,min(a[i].second,a[j].first)+max(a[i].second,a[j].first));
                    }
                    if(a[i].second!=-1 && a[j].second!=-1){
                        ans = max(ans,min(a[i].second,a[j].second)+max(a[i].second,a[j].second));
                    }
                    if(a[i].first!=-1 && a[j].second!=-1){
                        ans = max(ans,min(a[i].first,a[j].second)+max(a[i].first,a[j].second));
                    }
                }

            }
        }
        cout << ans <<'\n';
    }
}