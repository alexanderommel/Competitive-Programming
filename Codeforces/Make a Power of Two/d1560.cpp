#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include <cstdlib>
#include <algorithm>
#define fr(size, i) for (int i=0; i<size; i++)
#define ll long long
#define vll vector<long long >
#define pb push_back
using namespace std;

int solucion(string number){
    vll powers;
    fr(63,i){
        ll p = powl(2,i);
        powers.pb(p);
    }
    int lower_cost=LONG_MAX;
    for (auto p=powers.begin();p!=powers.end();++p){
        string stringPower = to_string(*p);
        ll digitPointer = 0;
        auto numDigitPointer = number.begin();
        while (numDigitPointer!=number.end()){
            if(*numDigitPointer==stringPower[digitPointer])
                digitPointer++;
            numDigitPointer++;
        }
        ll cost = (number.size()-digitPointer) + (stringPower.size()-digitPointer);
        if (cost<=lower_cost){
            lower_cost=cost;
        }
    }
    return lower_cost;
}

int main() {
    int t=0;
    cin >> t;
    while (t--){
        string number;
        cin >> number;
        cout << solucion(number) << endl;
    }
    return 0;
}