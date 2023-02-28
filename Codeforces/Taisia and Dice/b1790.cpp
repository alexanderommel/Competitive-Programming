#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(s,n,i) for (long long i=s; i<n; ++i)
#define pb push_back
#define fri(s,e,i) for (long long i=s; i>=e; --i)

int main(){

    int t;
    cin >> t;
    while(t-- ){
        int n,s,r;
        cin >> n >> s >> r;
        int mm = s-r;
        int resto = r / (n-1);
        //cout << "resto: "   <<resto<<'\n';
        int vec[n-1];
        fr(0,n-1,i){
            vec[i]=resto;
        }
        resto = r % (n-1);
        int p=0;
        while(resto--){
            p = p%(n-1);
            vec[p]++;
            p++;
        }
        cout << mm << " ";
        fr(0,n-1,i){
            cout << vec[i]<<" ";
        }
        cout <<'\n';
    }


}