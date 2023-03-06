#include <bits/stdc++.h>
using namespace std;

vector<int> grafo[1000000];
bool visita[1000000];

void dfs(int nodo){

    if(visita[nodo]){
        return;
    }
    else visita[nodo]=true;

    for(auto hijo:grafo[nodo])
    {
        dfs(hijo);
    }
}


int main() {


    for (int i = 0; i < 1000000; ++i) {
        visita[i] = false;
    }

    int m;
    cin >> m;
    while(m--){
        int p,h;
        cin >> p >> h;
        grafo[p].push_back(h);
    }
    dfs(1);

}