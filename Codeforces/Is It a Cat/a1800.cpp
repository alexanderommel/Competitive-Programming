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
        int a[4];
        for(int i=0;i<4;i++)    {
            a[i]=-1;
        }
        bool no_ans = false;
        for(int i=0;i<n;i++)    {
            if (s[i]=='m' || s[i]=='M' || s[i]=='e' || s[i]=='E' || s[i]=='o' || s[i]=='O' || s[i]=='w' || s[i]=='W'){
                if(s[i]=='m' || s[i]=='M'){
                    a[0]=i;
                    if(a[1]!=-1 || a[2]!=-1 || a[3]!=-1){
                        no_ans = true;
                        break;
                    }
                }
                if(s[i]=='e' || s[i]=='E'){
                    a[1]=i;
                    if(a[0]==-1 || a[2]!=-1 || a[3]!=-1){
                        no_ans = true;
                        break;
                    }
                }
                if(s[i]=='o' || s[i]=='O'){
                    a[2]=i;
                    if(a[0]==-1 || a[1]==-1 || a[3]!=-1){
                        no_ans = true;
                        break;
                    }
                }
                if(s[i]=='w' || s[i]=='W'){
                    a[3]=i;
                    if(a[0]==-1 || a[1]==-1 || a[2]==-1){
                        no_ans = true;
                        break;
                    }
                }
            }else{
                no_ans = true;
                break;
            }
        }
        if(no_ans){
            cout << "NO\n";
        }else{
            if(a[0]==-1 || a[1]==-1 || a[2]==-1 || a[3]==-1){
                cout << "NO\n";
            }else{
                cout << "YES\n";
            }
        }

    }
}