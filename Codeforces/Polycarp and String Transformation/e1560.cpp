#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <map>
#define fr(tamano, i) for (int i=0; i<tamano; i++)
#define fmap(map,puntero) for (auto puntero=map.begin(); puntero!=map.end(); puntero++)
using namespace std;


vector<char> letrasRemovidasEnOrden(string t){
    long int pos = t.size() -1;
    vector<char> letras;
    while(pos>=0){
        if (find(letras.begin(), letras.end(), t[pos]) != letras.end()){
            pos--;
            continue;
        }else{
            letras.push_back(t[pos]);
        }
        pos--;
    }
    return letras;
}

map<char, long int> tablaDeFrecuencias(string s){
    map<char, long int> frecuencias;
    fr(s.size(),i){
        frecuencias[s[i]]++;
    }
    return frecuencias;
}

void solver(string t){
    vector<char> letras = letrasRemovidasEnOrden(t);
    map<char,long int> tabla = tablaDeFrecuencias(t);
    int paso = letras.size();
    int tamano_original = 0;
    fr(letras.size(),k){
        int repeticiones = tabla[letras[k]];
        int num_original = repeticiones / paso;
        if (repeticiones%paso!=0){
            cout << "-1" << endl;
            return;
        }
        tamano_original = tamano_original + num_original;
        paso=paso-1;
    }
    reverse(letras.begin(), letras.end());
    string original;
    fr(tamano_original,m){
        original.push_back(t[m]);
    }
    string s = original;
    string testx=original;
    fr(letras.size(),l){
        s.erase(std::remove(s.begin(), s.end(), letras[l]), s.end());
        testx = testx.append(s);
    }
    if (testx!=t){
        cout << "-1" << endl;
        return;
    }
    cout << original <<  " ";
    fr(letras.size(),h){
        cout << letras[h];
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--){
        string t;
        cin >> t;
        solver(t);
    }
    return 0;
}
