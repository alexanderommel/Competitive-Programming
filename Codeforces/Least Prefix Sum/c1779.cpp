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
        int n,m;
        cin >> n >> m;
        vll a;
        vll s;
        fr(0,n,i){
            ll ai;
            cin >> ai;
            a.pb(ai);
            if(i>0){
                s.pb(s[i-1]+ai);
            }else{
                s.pb(ai);
            }
        }
        vector<pair<ll,int> >stack;
        ll z = s[m-1];
        //cout << "sum array\n";
        fr(0,m,i){
            //cout << s[i]<< " ";
            if(s[i]<s[m-1]){
                stack.pb({s[i],i});
            }
        }
        //cout << "\nstack array\n";
        //fr(0,stack.size(),i){
           // cout << stack[i].first << " ";
       // }
        //cout << '\n';
        int p1=m;
        int p2=stack.size()-1;
        ll ans=0;
        priority_queue<ll>  queue;
        while(!stack.empty()){
            fr(stack[p2].second+1,p1,j){
                if (a[j]>0){
                    queue.push(a[j]);
                }
            }
            p1 = stack[p2].second+1;
            if (z<=stack[p2].first){
                stack.pop_back();
                p2=stack.size()-1;
                continue;
            }
            ans++;
            ll top = queue.top();
            queue.pop();
            z-= (2* top) ;
        }


        s[m-1]=z;
        priority_queue<ll,vector<ll>, greater<>>  queue2;
        fr(m,n,i){
            s[i]=s[i-1]+a[i];
            if(s[i]<s[m-1]){
                stack.pb({s[i],i});
            }
        }

        p1=m;
        p2=0;
        z=0;
        while(p2<stack.size()){
            fr(p1,stack[p2].second+1,j){
                if (a[j]<0){
                    queue2.push(a[j]);
                }
            }
            p1 = stack[p2].second+1;
            if (s[m-1]<=stack[p2].first+z){
                p2++;
                continue;
            }
            ans++;
            ll top = queue2.top();
            queue2.pop();
            z+= (2* (-1*top)) ;
        }

        cout << ans <<'\n';


    }

    return 0;
}