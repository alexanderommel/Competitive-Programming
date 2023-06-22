#include <bits/stdc++.h>
#define pb push_back
#define vi vector<int>
#define ll long long
#define vll vector<long long>
#define pll pair<ll,ll>
using namespace std;
typedef std::tuple<int,int,int> mytuple;

ll val(char a){
    if (a=='A'){
        return 1;
    }
    if (a=='B'){
        return 10;
    }
    if (a=='C'){
        return 100;
    }
    if (a=='D'){
        return 1000;
    }
    return 10000;
}

ll atotal(string s, int n){
    ll total = 0;
    int asd[5]={0,0,0,0,0};
    for (int i = n-1; i >= 0; --i) {
        asd[s[i]-'A']+=1;
        if (s[i]=='A'){
            if (asd[1]+asd[2]+asd[3]+asd[4]>0){
                total-=val('A');
            }else{
                total+=val('A');
            }
        }
        if (s[i]=='B'){
            if (asd[2]+asd[3]+asd[4]>0){
                total-=val('B');
            }else{
                total+=val('B');
            }
        }
        if (s[i]=='C'){
            if (asd[3]+asd[4]>0){
                total-=val('C');
            }else{
                total+=val('C');
            }
        }
        if (s[i]=='D'){
            if (asd[4]>0){
                total-=val('D');
            }else{
                total+=val('D');
            }
        }
        if (s[i]=='E'){
            total+=val('E');
        }
    }
    return total;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n = s.size();
        ll total = atotal(s,n);
        ll ans = total;
        for (int i = 0; i < 4; ++i) {
            char letter = i + 'A';
            int z = 0;
            int pol=-1;
            int p = -1;
            int p2=-1;
            int p3=-1;
            ll rel1 = 0;
            for (int j = n-1; j >=0 ; --j) {
                if (s[j]==letter){
                    if(z<2){
                        rel1++;
                    }
                    if (pol==-1){
                        pol=j;
                    }else{
                        p=j;
                    }
                }
                if (s[j]>letter){
                    z++;
                    if (z==1){
                        p2=j;
                    }
                    if (z==2){
                        p3=j;
                    }
                }

            }
            if (z>=1){
                for (int j = 0; j < 5; ++j) {
                    char letra = j + 'A';
                    string ttt = s;
                    ttt[p2]=letra;
                    ll tot = atotal(ttt,n);
                    ans=max(ans,tot);
                }
            }
            if (z==2){
                for (int j = 0; j < 5; ++j) {
                    char letra = j + 'A';
                    string ttt = s;
                    ttt[p3]=letra;
                    ll tot = atotal(ttt,n);
                    ans=max(ans,tot);
                }
            }
            if (p!=-1){
                for (int j = 0; j < 5; ++j) {
                    char letra = j + 'A';
                    string ttt = s;
                    ttt[p]=letra;
                    ll tot = atotal(ttt,n);
                    ans=max(ans,tot);
                }
            }
            if (pol!=-1){
                for (int j = 0; j < 5; ++j) {
                    char letra = j + 'A';
                    string ttt = s;
                    ttt[pol]=letra;
                    ll tot = atotal(ttt,n);
                    ans=max(ans,tot);
                }
            }
        }
        cout << ans <<'\n';
    }
}