#include <bits/stdc++.h>
using namespace std;

int main(){

    int t;
	cin>>t;
	for(int i=0; i<t; i++){
		int d=0;
		int a=0;
        int n;
		cin>>n;
		for(int j=0; j<n; j++){
            int b;
			cin>>b;
			d+=(b-a)/120;
			a=b;
		}
		d+=(1440-a)/120;

		if(d>=2){
			cout<<"YES"<<'\n';
		}
		else{
			cout<<"NO"<<'\n';
		}
	}
	return 0;
}