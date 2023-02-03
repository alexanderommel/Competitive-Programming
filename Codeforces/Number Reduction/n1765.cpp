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


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        int p=0;
        int p2=0;
        bool worry = true;
        vi ans;
        vi leading;
        priority_queue<pair<int,int>> pq; // second is index
        while(p<s.size() && k>0){
            //cout << "test p of: "<<p<<'\n';
            int d = s[p]-'0';
            while(!pq.empty() && k>0){
                if(pq.size()==1 && d==0 && worry){
                    break;
                }
                if(pq.top().first>d){
                    if (pq.top().second<p2  && leading.size()>=k){
                        pq.pop();
                        continue;
                    }
                    //cout << "remove top value of " <<pq.top().first<<'\n';
                    ans.pb(pq.top().second);
                    k--;
                    pq.pop();
                    if(pq.empty()){
                        if(worry){
                            fr(0,leading.size(),xxx){
                                ans.pb(leading[xxx]);
                                k--;
                            }
                            leading.clear();
                        }
                    }
                }else{
                    break;
                }
            }
            if(k==0){
                break;
            }
            if(d!=0){
                pq.push({d,p});
            }else{
                if(pq.size()>0 && worry){
                    leading.pb(p);
                    p2=p;
                    //cout << "add leading zero\n"    ;
                }
            }
            if(leading.size()>=k){
                //cout << "end leadings "<<'\n';
                worry=false;
            }
            p++;
        }
        std::sort(ans.begin(), ans.end());
        string sANS = "";
        fr(0,s.size(),i){
            bool found = binary_search(ans.begin(),ans.end(),i);
            if(!found){
                sANS+=s[i];
            }
        }
        fr(0,sANS.size()-k,i){
            cout << sANS[i]<<"";
        }
        cout << '\n';
    }
}

int main2(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        string x;
        cin >> x;
        int k;
        cin >> k;
        int p=0;
        bool ignore_leading=true;
        while(k>0){
            int mp;
            int minn=INT_MAX;
            if (x.size()-p==k){
                break;
            }
            fr(p,p+k+1,i){
                if (x[i]<minn){
                    if (x[i]=='0' && ignore_leading){
                        continue;
                    }
                    mp=i;
                    minn = x[i];
                }
            }
            k-=(mp-p);
            cout << x[mp];
            p=mp+1;
            ignore_leading = false;
        }
        if (k==0 && p<=x.size()-1){
            fr(p,x.size(),i){
                cout << x[i];
            }
        }
        cout << '\n';
    }


    return 0;
}
