// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
#define ll long long
using namespace std;

typedef pair<int,pair<int,pair<char,char>>> py;

int main() {
    int t;
    cin >> t;
    while(t--){
        string s1;
        string s2;
        int l,q;
        cin >> s1 >> s2 >> l >> q;
        int n = s1.size();
        int eva[n];
        int ans=0;
        for(int i=0;i<n;i++){
            if(s1[i]!=s2[i]){
                eva[i]=1;
                ans++;
            }else{
                eva[i]=0;
            }
        }
        priority_queue<py,vector<py>,greater<py>> pq;
        int seconds=0;
        while(q--){
            seconds++;
            //cout << "s: "<< seconds <<'\n';
            int type;
            cin >> type;
            if(!pq.empty()){
                py my = pq.top();
                if(my.first-seconds==0){
                    s1[my.second.first-1]=my.second.second.first;
                    s2[my.second.first-1]=my.second.second.second;
                    int diff = 0;
                    if(s1[my.second.first-1]!=s2[my.second.first-1]){
                        diff=1;
                    }
                    //cout << eva[my.second.first-1] <<'\n';
                    if(eva[my.second.first-1]==0){
                        if(diff==1) ans++;
                    }
                    if(eva[my.second.first-1]==1){
                        if(diff==0) ans--;
                    }
                    eva[my.second.first-1]=diff;
                    pq.pop();
                }
            }
            if(type==1){
                int pos;
                cin >> pos;
                py myn = {seconds+l,{pos,{s1[pos-1],s2[pos-1]}}};
                pq.push(myn);
                s1[pos-1]=s2[pos-1];
                if(eva[pos-1]==1){
                    ans--;
                }
                eva[pos-1]=0;
            }
            if(type==2){
                int ta,pa,tb,pb;
                cin >> ta >> pa >> tb >> pb;
                int ai=0;
                int bi=0;
                if(ta==1){
                    char temp = s1[pa-1];
                    if(tb==1){
                        s1[pa-1]=s1[pb-1];
                        s1[pb-1]=temp;
                    }else{
                        s1[pa-1]=s2[pb-1];
                        s2[pb-1]=temp;
                    }
                }else{
                    char temp = s2[pa-1];
                    if(tb==1){
                        s2[pa-1]=s1[pb-1];
                        s1[pb-1]=temp;
                    }else{
                        s2[pa-1]=s2[pb-1];
                        s2[pb-1]=temp;
                    }
                }
                if(s1[pa-1]!=s2[pa-1]) ai=1;
                if(s1[pb-1]!=s2[pb-1]) bi=1;
                if(eva[pa-1]==0){
                    if(ai==1) ans++;
                }
                if(eva[pa-1]==1){
                    if(ai==0) ans--;
                }
                if(eva[pb-1]==0){
                    if(bi==1) ans++;
                }
                if(eva[pb-1]==1){
                    if(bi==0) ans--;
                }
                eva[pa-1]=ai;
                eva[pb-1]=bi;
            }
            if(type==3){
                if(ans==0){
                    cout << "YES\n";
                }else{
                    cout << "NO\n";
                }
            }
            //cout << "s1: "<<s1 << "   -   s2: "<<s2<<'\n';
            //cout << "ans: "<<ans<<'\n';
        
        }
    }
}
