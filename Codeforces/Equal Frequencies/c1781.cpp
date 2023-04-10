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

typedef std::pair<ll,ll> mypair;
bool my_comparator ( const mypair& l, const mypair& r){
    return l.second > r.second;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n; string s;
        cin >> n; cin >> s;

        vector<pair<int,int>> f(26);
        fr(0,26,i){
            f[i]={i,0};
        }
        fr(0,n,i){
            f[s[i]-'a'].second++;
        }

        std::sort(f.begin(), f.end(),my_comparator);


        //fr(0,26,i){
         //   char lt = f[i].first+'a';
         //   cout << "letra "<<lt<<" con frecuencia: "<<f[i].second << '\n';
        //}


        int ans=INT_MAX;
        string resFinal=s;

        fr(1,27,i){
            int len = n/i;
            if (len*i==n){

                string respuesta="";
                int localAns=0;
                int constr[26];
                fr(0,26,cc){
                    constr[cc] = -1;
                }
                fr(0,i,m){
                    constr[f[m].first]=f[m].second;
                }

                int lp=0;

                //cout << "Testing size " << len << '\n';
                //fr(0,26,xxxx){
                 //   char letra = xxxx+'a';
                 //   cout << "("<<letra<<","<<constr[xxxx]<<") ";
                //}
                //cout << '\n';

                fr(0,n,j) {

                    if (constr[s[j] - 'a'] <0 || constr[s[j] - 'a'] > len) {
                        localAns++;

                        while(lp<26){
                            if (constr[lp]>=0 && constr[lp] < len){
                                constr[lp]++;
                                constr[s[j] - 'a']--;
                                char letraN = lp + 'a';
                                respuesta = respuesta + letraN;
                                break;
                            }
                            lp++;
                        }



                        //fr(0, 26, m) {
                          //  if (constr[m] >=0 && constr[m] < len) {
                            //    constr[m]++;
                              //  constr[s[j] - 'a']--;
                                //char letraN = m + 'a';
                                //respuesta = respuesta + letraN;
                                //break;
                            //}
                        //}



                    } else {
                        char letraN = s[j];
                        respuesta = respuesta + letraN;
                    }
                }

                //cout << "ans for this length is: " << localAns << '\n';
                //cout << "string for this length is: " << respuesta << '\n';

                if (localAns<ans){
                    ans = localAns;
                    resFinal = respuesta;
                }

            }
        }

        cout << ans <<'\n';
        cout << resFinal << '\n';

    }

    return 0;
}

