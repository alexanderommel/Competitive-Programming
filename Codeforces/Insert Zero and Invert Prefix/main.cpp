#include<iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n];
        int b[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
         
        }
        if(a[n-1]==1){
            cout << "NO"<<'\n';
            continue;
        }
        int p=0;
        for(int i=0;i<n;i++){
            if(a[i]==1){
                p++;
            }else{
                p=0;
            }
            b[i]=p;
        }
        int g=-1;
        int ans[n];
        for(int i=n-1;i>=0;i--){
            if(a[i]==0){
                ans[n-1-i]=0;
                g=-1;
            }else{
                if(b[i]==1 && g==-1){
                    ans[n-1-i]=1;
                }else{
                    if(b[i]>1 && g==-1){
                        g=b[i];
                        ans[n-1-i]=0;
                        continue;
                    }
                    if(b[i]>1 && g!=-1){
                        ans[n-1-i]=0;
                        continue;
                    }
                    ans[n-1-i]=g;
                }
            }
        }
        cout << "YES\n";
        for(int i=0;i<n;i++){
            cout << ans[i]<< " ";
        }
        cout << '\n';
    }
    return 0;
}