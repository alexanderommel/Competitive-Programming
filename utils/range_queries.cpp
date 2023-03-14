#include <bits/stdc++.h>
using namespace std;

// ** BIT **//

void update(int *BIT,int index, int value, int n){
    int k = index;
    while(k<=n){
        BIT[k]+=value;
        k += k&-k;
    }
}

int sum(int *BIT, int index){
    if (index==0){
        return 0;
    }
    int k = index;
    int ans = 0;
    while(k>0){
        ans+=BIT[k];
        k -= k&-k;
    }
    return ans;
}

int *buildBIT(int n){
    int *BIT = new int[n+1];
    for(int i=1; i<=n; ++i){
        BIT[i]=0;
    }
    return BIT;
}