#include<bits/stdc++.h>
using namespace std;



int main(){

   int t;
   cin>>t;

   while(t--){

    int n,f=0,l=0;
    cin>>n;
    string s;
    cin>>s;
    for(int i=0;i<n;i++){
      if(s[i]=='(')f++;
      else f--;
      l=min(f,l);
    }   
    cout<<abs(l)<<'\n';
    
   }
   
}