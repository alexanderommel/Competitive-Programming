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

    int n,m;
    cin >> n >> m;
    string s;
    cin >> s;

    int LOG[n+1][6];

    fr(0,n+1,x){
        fr(0,6,z){
            LOG[x][z]=0;
        }
    }

    int LOCAL=0;
    int k=0;
    fr(0,n,j){
        k = j/3;
        if (j==(0+3*k) && s[j]!='a'){
            LOCAL++;
        }
        if (j==(1+3*k) && s[j]!='b'){
            LOCAL++;
        }
        if (j==(2+3*k) && s[j]!='c'){
            LOCAL++;
        }
        LOG[j+1][0]=LOCAL;
    }


    k=0;
    LOCAL=0;
    fr(0,n,j){
        k = j/3;
        if (j==(0+3*k) && s[j]!='a'){
            LOCAL++;
        }
        if (j==(1+3*k) && s[j]!='c'){
            LOCAL++;
        }
        if (j==(2+3*k) && s[j]!='b'){
            LOCAL++;
        }
        LOG[j+1][1]=LOCAL;
    }

    k=0;
    LOCAL=0;
    fr(0,n,j){
        k = j/3;
        if (j==(0+3*k) && s[j]!='b'){
            LOCAL++;
        }
        if (j==(1+3*k) && s[j]!='a'){
            LOCAL++;
        }
        if (j==(2+3*k) && s[j]!='c'){
            LOCAL++;
        }
        LOG[j+1][2]=LOCAL;
    }

    k=0;
    LOCAL=0;
    fr(0,n,j){
        k = j/3;
        if (j==(0+3*k) && s[j]!='b'){
            LOCAL++;
        }
        if (j==(1+3*k) && s[j]!='c'){
            LOCAL++;
        }
        if (j==(2+3*k) && s[j]!='a'){
            LOCAL++;
        }
        LOG[j+1][3]=LOCAL;
    }


    k=0;
    LOCAL=0;
    fr(0,n,j){
        k = j/3;
        if (j==(0+3*k) && s[j]!='c'){
            LOCAL++;
        }
        if (j==(1+3*k) && s[j]!='a'){
            LOCAL++;
        }
        if (j==(2+3*k) && s[j]!='b'){
            LOCAL++;
        }
        LOG[j+1][4]=LOCAL;
    }

    k=0;
    LOCAL=0;
    fr(0,n,j){
        k = j/3;
        if (j==(0+3*k) && s[j]!='c'){
            LOCAL++;
        }
        if (j==(1+3*k) && s[j]!='b'){
            LOCAL++;
        }
        if (j==(2+3*k) && s[j]!='a'){
            LOCAL++;
        }
        LOG[j+1][5]=LOCAL;
    }


    fr(0,m,i){
        int l,r;
        cin >> l >> r;
        int ANS=INT_MAX;

        ANS = min(ANS,LOG[r][0]-LOG[l-1][0]);
        ANS = min(ANS,LOG[r][1]-LOG[l-1][1]);
        ANS = min(ANS,LOG[r][2]-LOG[l-1][2]);
        ANS = min(ANS,LOG[r][3]-LOG[l-1][3]);
        ANS = min(ANS,LOG[r][4]-LOG[l-1][4]);
        ANS = min(ANS,LOG[r][5]-LOG[l-1][5]);


        cout << ANS << '\n';

    }

    return 0;
}
