#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
	cin>>t;
	while(t--)
	{
		int ans=0;
		int a,b,c,d,al,bb;
		cin>>a>>b>>c>>d;
		if(a==0) puts("1");
		else 
		cout<<a+min(b,c)*2+min(a+1,abs(b-c)+d)<<"\n";
	}
}