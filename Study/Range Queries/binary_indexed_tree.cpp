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

/**
 * Binary Indexing Tree
 * **/


void update(int *BIT,int index, int value, int n){
    int k = index;
    while(k<=n){
        BIT[k]+=value;
        // obtenemos el bit menos significativo y lo aumentamos
        // al aumentar nos desplazamos en el rango de importancia
        k += k&-k; //actualizamos el rango de importancia de el número
    }
}

int sum(int *BIT, int index){
    int k = index;
    int ans = 0;
    while(k>0){
        ans+=BIT[k];
        k -= k&-k; // quitamos el lsb y retrocedemos en el rango de importancia
    }
    return ans;
}

int *buildBIT(int N[], int n){
    int *BIT = new int[n+1];
    fr(1,n+1,i){
        BIT[i]=0;
    }
    fr(0,n,i){
        update(BIT,i+1,N[i],n);
    }
    return BIT;
}

int main(){

    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int a[] = {1,3,4,8,6,1,4,2};
    int n = 8;
    int *BIT  = buildBIT(a,n);

    fr(1,n+1,h){
        cout << BIT[h] << '\n';
    }

    cout << '\n'<<sum(BIT,7) << '\n';
    cout << '\n'<<sum(BIT,3) << '\n';

    a[6] +=2;

    update(BIT,6,-2,n);
    cout << '\n'<<sum(BIT,7) << '\n';
    cout << '\n'<<sum(BIT,3) << '\n';

    return 0;
}
