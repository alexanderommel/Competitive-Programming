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

ll combinaciones(ll n){
    ll ans = n*(n+1);
    return ans/2;
}

 bool algoritmo_de_luhn(string s){
    bool go=false;
    string t=s;
    if(s.size()>1){
        fri(s.size()-1,0,i){
            int digito = s[i]-'0';
            if(go){
                digito=digito*2;
                string doblar = to_string(digito);
                if(doblar.size()>1){
                    digito = (doblar[0]-'0') + (doblar[1]-'0');
                }
                go=false;
            }else{
                go=true;
            }
            char digito_letra = digito + '0';
            t[i]=digito_letra;
        }
    }
    ll sum=0;
    fr(0,t.size()-1,i){
        sum+=(t[i]-'0');
    }
    sum= sum*9;
    sum = sum%10;
    if(sum==(s[s.size()-1]-'0')){
        return true;
    }else{
        return false;
    }
 }

int main23454(){
    string s;
    cin >> s;
    int a=0,r=0;
    ll ans=0;
    fr(0,s.size(),i){
        if(s[i]=='1'){
            a++;
        }else{
            r++;
        }
        if(a>0 && r>0){
            a--;
            r--;
            ans+=2;
        }
    }
    cout << ans <<'\n';
}

int mainaaa(){
    string s;
    cin >> s;
    char current = 'A';
    ll ans=0;
    fr(0,s.size(),i){
        if(s[i]=='H'){
            if(current=='O'  || current=='N'){
                continue;
            }else{
                current = 'H';
            }
            continue;
        }
        if(s[i]=='O'){
            if(current=='H'){
                current = 'O';
            }
            continue;
        }
        if(s[i]=='N'){
            if(current=='O'){
                current = 'N';
            }
            continue;
        }
        if(s[i]=='I'){
            if(current=='N'){
                current = 'A';
                ans++;
            }
            continue;
        }
    }
    cout << ans <<'\n';
}

int problema2(){

    int n;
    cin >> n;
    string s;
    cin >> s;
    int posicion_x;
    fr(0,s.size(),i){
        if(s[i]=='x'){
            posicion_x=i;
            break;
        }
    }
    ll ans=10;
    fr(0,10,i){
        string t = s;
        char nuevo_numero = i+'0';
        t[posicion_x]=nuevo_numero;
        if(algoritmo_de_luhn(t)){
            ans=min(ans,i);
        }
    }
    cout << ans << '\n';


}

int mainAAAAAAAA(){
    int n=3, p=3, contador=0;
    int W[3]={1,2,3};
    int S[n+1];
    for(int i=1;i<=n;i++){ // Tamaño de los intervalos
        for(int j=0;j<=(n-i);j++){ // Recorremos el arreglo de los pesos
            int suma=0;
            for(int z=j;z<(j+i);z++){ // Sumamos los numeros dentro del intervalo
                suma+=W[z];
            }
            if(suma<=p){
                contador++;
            }
        }
    }
    cout << "Respuesta: "<<contador;
}

int mainZZZZZZZZZZZZZZZZZZZZZ(){
    int n=3, p=3, contador=0;
    int W[3]={1,2,3};
    int S[n+1];
    S[0]=0;
    for(int i=1;i<=n;i++){
        S[i]=S[i-1]+W[i-1];
    }
    for(int i=1;i<=n;i++){ // Tamaño de los intervalos
        for(int j=0;j<=(n-i);j++){ // Recorremos el arreglo de los pesos
            int L=j+1;
            int R=j+i;
            int suma = S[R]-S[L-1];
            if(suma<=p)
                contador++;
        }
    }
    cout << "Respuesta: "<<contador;
}

int main(){

    ll n=3, p=3;
    ll W[3]={1,2,3};

    ll S[n+2];
    S[0]=0;
    S[n+1]=LONG_LONG_MAX;
    for(ll i=1;i<=n;i++){
        S[i]=S[i-1]+W[i-1];
    }
    vector<pair<ll,ll>> INTERVALOS_BUENOS;
    int L=1;
    int R=1;
    bool ULTIMO_BUENO=false;
    while(R<=n+1){
        ll suma = S[R]-S[L-1];
        if(suma>p){
            if(ULTIMO_BUENO){
                INTERVALOS_BUENOS.pb({L+1,R});
                ULTIMO_BUENO=false;
            }
            L++;
            if(R<L)
                R = L;
        }else{
            R++;
            ULTIMO_BUENO=true;
        }
    }

    if(!INTERVALOS_BUENOS.empty()){
        pair<ll,ll> intervalo=INTERVALOS_BUENOS[0];
        if(INTERVALOS_BUENOS.size()>1){
            ll RESPUESTA=0;
            for(ll z=1;z<INTERVALOS_BUENOS.size();z++){
                pair<ll,ll> other =  INTERVALOS_BUENOS[z];
                RESPUESTA+= combinaciones(intervalo.second-intervalo.first+1);
                if(other.first<=intervalo.second){ // INTERSECCIÓN
                    ll dif = intervalo.second-other.first+1;
                    RESPUESTA-= combinaciones(dif);
                }
                intervalo=other;
            }
            RESPUESTA+= combinaciones(intervalo.second-intervalo.first+1);
            cout << RESPUESTA << '\n';
        }else{
            cout << combinaciones(intervalo.second-intervalo.first+1)<<'\n';
        }
    }else{
        cout << 0 <<'\n';
    }


}

int main233111(){
    int n,q;
    cin >> n >> q;
    ll prefix[n+1];
    ll first;
    cin >> first;
    prefix[0]=first;
    fr(1,n,i){
        ll nm;
        cin >> nm;
        prefix[i]=prefix[i-1]+nm;
    }
    prefix[n]=LONG_LONG_MAX;
    while(q--){
        vector<pair<int,int>> BUENOS;
        ll w;
        cin >> w;
        int lp=0;
        int rp=0;
        bool sumar=false;
        while(rp<=n){
            ll suma_prefix = prefix[rp];
            if(lp>0){
                suma_prefix = suma_prefix - prefix[lp-1];
            }
            if(suma_prefix>w){
                if(sumar){
                    BUENOS.pb({lp+1,rp});
                    sumar = false;
                }
                lp++;
                if(rp<lp){
                    rp= lp;
                }
            }else{
                sumar=true;
                rp++;
            }
        }
        if(BUENOS.size()>0){
            pair<ll,ll> ff=BUENOS[0];
            if(BUENOS.size()>1){
                ll ans=0;
                fr(1,BUENOS.size(),z){
                    pair<ll,ll> other =  BUENOS[z];
                    ans+= combinaciones(ff.second-ff.first+1);
                    if(other.first<=ff.second){
                        ll dif = ff.second-other.first+1;
                        ans-= combinaciones(dif);
                    }
                    ff=other;
                }
                ans+= combinaciones(ff.second-ff.first+1);
                cout << ans << '\n';
            }else{
                cout << combinaciones(ff.second-ff.first+1)<<'\n';
            }
        }else{
            cout << 0 <<'\n';
        }
    }
    return 0;
}