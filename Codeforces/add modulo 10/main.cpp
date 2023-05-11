#include <bits/stdc++.h>
#define pb push_back
#define vi vector<int>
#define ll long long
#define vll vector<long long>
#define pll pair<ll,ll>
using namespace std;
typedef std::tuple<int,int,int> mytuple;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        ll a[n];
        int im=-1;
        ll max=-1;
        for(int i=0;i<n;i++){
            cin >> a[i];
            if(a[i]>=max){
                im=i; 
                max=a[i];
            }
        }
        int c=10;
        ll b = a[im];
        bool ans=false;
        while(c>=0 && !ans){

            int k=0;
            bool local_ans= true;

            while(k<n && local_ans){
                ll d = a[k];

                int z = 10;
                bool no_ans = false;
                while(z>=0 && !no_ans){

                    if (d%10==0){
                        if (b==d){
                            no_ans = true;
                        }
                        break;
                    }
                    if (d%5==0){
                        if (b==d || b==(d+5)){
                            no_ans = true;
                        }
                        break;
                    }

                    if(d%2==0){
                        ll k = (b-d)/20;
                        if ((d+(20*k))==b){
                            no_ans=true;
                        }
                    }else{
                        if(d==b){
                            no_ans = true;
                        }
                    }

                    d = d + (d%10);
                    z--;
                }

                if(!no_ans){
                    local_ans=false;
                }

                k++;
            }

            if (local_ans){
                ans=true;
            }

            b = b + (b%10);
            c--;
        }
        if(ans){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }
}