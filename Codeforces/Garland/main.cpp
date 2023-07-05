#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		char s[10];
		scanf("%s",s);
		sort(s,s+4);
		if(s[0]==s[3])
			puts("-1");
		else if(s[0]==s[2]||s[1]==s[3])
			puts("6");
		else
			puts("4");
	}
	return 0;
}
