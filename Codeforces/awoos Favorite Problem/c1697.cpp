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

    int q;
    cin >> q;
    while(q--){
        int n;
        cin >> n;
        string s,t;
        cin >> s >> t;

        if (s[n-1]=='a' && t[n-1]=='b'){
            cout << "NO" << '\n';
            continue;
        }
        if (s[0]=='b' && t[0]=='a'){
            cout << "NO" << '\n';
            continue;
        }
        if ((s[0]=='c' && t[0]!='c') || (s[n-1]!='c' && t[n-1]=='c')){
            cout << "NO" << '\n';
            continue;
        }

        map<char,int> f1;
        map<char,int> f2;

        fr(0,n,z){
            f1[s[z]]++;
            f2[t[z]]++;
        }

        if(!(f1['a']==f2['a'] && f1['b']==f2['b'] && f1['c']==f2['c'])){
            cout << "NO" << '\n';
            continue;
        }


        int i =0;
        int j =0;
        f1['a']=0;
        f1['b']=0;
        f1['c']=0;
        f2['a']=0;
        f2['b']=0;
        f2['c']=0;
        bool no= false;
        while(i<n && j<n){

            if (s[i]=='c'){
                i = j;
            }

            if (s[i]=='c'){
                if (t[i]!='c'){
                    no = true;
                    break;
                }
            }



            if(s[i]=='a'){
                if(s[j]=='c' || t[j]=='c'){
                    //cout << "a broken at index: " << j <<'\n';

                    //cout << "after a " << '\n';
                    //cout << "f1("<<f1['a']<<","<<f1['b']<<"," <<f1['c']<<")"<<'\n';
                    //cout << "f2("<<f2['a']<<","<<f2['b']<<"," <<f2['c']<<")"<<'\n';

                    if ((s[j]=='b' && (t[j]=='b' || t[j]=='c') || (s[j]=='c' && t[j]=='c'))){
                        if (!(f1['a']==f2['a'] && f1['b']==f2['b'] && f1['c']==f2['c'])){
                            no = true;
                            break;
                        }else{
                            i = j;
                        }
                    }else{
                        no = true;
                        break;
                    }
                }
            }
            if(s[i]=='b'){
                if(s[j]=='a' || t[j]=='a'){
                    //cout << "b broken at index: " << j <<'\n';

                    //cout << "after b " << '\n';
                    //cout << "f1("<<f1['a']<<","<<f1['b']<<"," <<f1['c']<<")"<<'\n';
                    //cout << "f2("<<f2['a']<<","<<f2['b']<<"," <<f2['c']<<")"<<'\n';

                    if ((s[j]=='a' && (t[j]=='b' || t[j]=='a') || (s[j]=='c' && t[j]=='c'))){
                        if (!(f1['a']==f2['a'] && f1['b']==f2['b'] && f1['c']==f2['c'])){
                            no = true;
                            break;
                        }else{
                            i = j;
                        }
                    }else{
                        no = true;
                        break;
                    }
                }
            }



            f1[s[j]]++;
            f2[t[j]]++;
            j++;


        }

        if (no){
            cout << "NO" << '\n';
        }else{
            if(f1['a']==f2['a'] && f1['b']==f2['b'] && f1['c']==f2['c']){
                cout << "YES" << '\n';
            }else{
                cout << "NO" << '\n';
            }
        }

    }


    return 0;
}
