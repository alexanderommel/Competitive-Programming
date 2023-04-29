#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define fr(s,n,i) for (long long i=s; i<n; ++i)


int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        int a[27];
        for(int i=0;i<27;i++){
            a[i]=-1;
        }
        bool ans=true;
        int start=1;
        for(int i=0;i<s.size();i++){
            if(a[s[i]-'a']==-1){
                if(start==1){
                    a[s[i]-'a']=0;
                    start=0;
                }else{
                    a[s[i]-'a']=1;
                    start=1;
                }
                continue;
            }
            if(start==1){
                if(a[s[i]-'a']==1){
                    ans=false;
                    break;
                }
                start=0;
            }else{
                if(a[s[i]-'a']==0){
                    ans=false;
                    break;
                }
                start=1;
            }
        }

        if(ans){
            cout << "YES\n";
            continue;
        }

        start = 0;
        ans = true;

        for(int i=0;i<27;i++){
            a[i]=-1;
        }

        for(int i=0;i<s.size();i++){
            if(a[s[i]-'a']==-1){
                if(start==1){
                    a[s[i]-'a']=0;
                    start=0;
                }else{
                    a[s[i]-'a']=1;
                    start=1;
                }
                continue;
            }
            if(start==1){
                if(a[s[i]-'a']==1){
                    ans=false;
                    break;
                }
                start=0;
            }else{
                if(a[s[i]-'a']==0){
                    ans=false;
                    break;
                }
                start=1;
            }
        }

        if(ans){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }

    }
}