#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(s,n,i) for (long long i=s; i<n; ++i)
#define fri(s,e,i) for (long long i=s; i>=e; --i)

int main(){
    int n;
    cin >> n;
    int a=0;
    int b=0;
    string s;
    cin >> s;
    fr(0,n,i){
        if(s[i]=='+'){
            a++;
        }else{
            b++;
        }
    }
    if(a>b){
        swap(a,b);
    }
    int q;
    cin >> q;
    while(q--){
        ll aj,bj;
        cin >> aj >> bj;
        int l=0;
        int r=min(a,b);
        //cout << "bs for numbers ("<<aj<<","<<bj<<") and ranges from [0,"<<r<<"]\n";
        bool ans=false;
        while(l<=r){
            int x = (l+r)/2;
            //cout << "testing x: "<<x<<'\n';
            int d= a-x;
            int e =b-x;
            //cout << "with values ("<<d<<","<<e<<")\n";
            if((d*max(aj,bj))-(e*min(aj,bj))==0){
                ans=true;
                break;
            }
            if((d*max(aj,bj))-(e*min(aj,bj))>0){
                l = x+1;
            }else{
                r = x-1;
            }
        }
        if(ans){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }

}