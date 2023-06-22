#include <bits/stdc++.h>
using namespace std;
int d,a[3];
int main(){
	cin>>a[0]>>a[1]>>a[2]>>d;
	sort(a,a+3);
	cout<<max(0,d-(a[1]-a[0]))+max(0,d-(a[2]-a[1]));
}