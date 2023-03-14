#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define fr(s,n,i) for (long long i=s; i<n; ++i)

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        string s;
        cin >> s;
        int m[27];
        int M[27];
        for(int i=0;i<27;i++)   {
            m[i]=0;
            M[i]=0;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(tolower(s[i],locale())==s[i]){
                m[s[i]-'a']++;
            }else{
                char minusc = tolower(s[i],locale());
                M[minusc-'a']++;
            }
        }
        for(int i=0;i<27;i++){
            int ai = m[i];
            int bi = M[i];
            ans+=min(ai,bi);
            m[i]-=min(ai,bi);
            M[i]-=min(ai,bi);
        }
        for(int i=0;i<27;i++){
            if(k==0){
                break;
            }
            int ci = max(m[i],M[i]);
            int to_add = ci/2;
            ans += min(k,to_add);
            k-=min(k,to_add);
        }
        cout << ans <<'\n';

    }
}