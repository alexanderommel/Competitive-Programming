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

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n,m,k;
        cin >> n >>m >>k ;
        vi a;
        viin(a,k);
        int p=0;
        bool good=true;
        priority_queue<int> queue;
        int stacked = k+1;
        while(good && p<k){
            int current = a[p];
            if(current==stacked-1){
                stacked = current;
                while(queue.size()>0){
                    int top = queue.top();
                    if (top==stacked-1 ){
                        stacked = top;
                        queue.pop();
                    }else{
                        break;
                    }
                }
            }else{
                if(n==1 || m==1){
                    good = false;
                }
                queue.push(current);
                if(queue.size()>=((n*m)-3)){
                    good = false;
                }
            }
            p++;
        }

        if(good){
            cout << "YA\n";
        }else{
            cout << "TIDAK\n";
        }

    }

    return 0;
}