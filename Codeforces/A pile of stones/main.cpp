#import<bits/stdc++.h>
int i,m,n,t;char s[105];
main(){
    scanf("%d%s",&n,s);
    for(i=0;s[i];i++)s[i]<45?t++:t--,m<t?:m=t;;
    cout << t - m << '\n';
}