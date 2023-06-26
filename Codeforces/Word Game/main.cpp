#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;

void sol(){
	
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s[(3*n)+1];
        map<string,int>m;
        int c=0;
	    for(int i=0;i<n*3;i++)cin>>s[i],m[s[i]]++;
	    for(int i=0;i<n*3;i++){
		    if(m[s[i]]==1)c+=3;else if(m[s[i]]==2)c+=1;
		    if((i+1)%n==0){
			cout<<c<<" ";c=0;continue;
		    }
	    }
	    cout<<'\n',:
    }
}