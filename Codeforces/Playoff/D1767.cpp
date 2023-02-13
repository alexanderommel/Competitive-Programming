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
#define LSB(i)  ((i) & -(i))

using namespace std;
typedef map<ll,ll, greater<ll>> desc_map;
typedef std::pair<ll,ll> mypair;
typedef std::priority_queue<ll> maxqueue;
typedef std::priority_queue <ll, vector<ll>, greater<ll>> minqueue;

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ls=0; int rs=0;
    int cl=0; int cr=0;
    fr(0,s.size(),i){
        if(s[i]=='1'){
            ls+=pow(2,cr);
            cr++;
        }else{
            rs+=pow(2,cl);
            cl++;
        }
    }
    //cout << "ls:"<<ls<<'\n';
    //cout <<" rs:"<<rs<<'\n';
    fr(ls,(pow(2,n)-rs),i){
        cout << i + 1 << " ";
    }
}