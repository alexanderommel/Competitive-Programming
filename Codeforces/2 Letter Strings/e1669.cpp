#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#define pb push_back
#define ll long long
#define fr(size, i) for (int i=0; i<size; i++)
#define len(arr) arr.size()
#define vs vector<string>
using namespace std;

void sol(int n, vs strings){
    n = len(strings);
    vector<char> space = {'a','b','c','d','e','f','g','h','i','j','k'};
    std::reverse(strings.begin(), strings.end());
    map<string,ll> freq;
    fr(len(strings),i){
        freq[strings[i]]++;
    }
    ll ans=0;
    fr(n,i){
        char left = strings[i][0];
        char right = strings[i][1];
        vs combinations;
        for (int l = 0; l < 2; ++l) {
            for (char j = 'a'; j <= 'k'; ++j) {
                string merge;
                if (l==0 && j==right)
                    continue;
                if (l==1 && j==left)
                    continue;
                if (l==0){
                    merge.pb(left);
                    merge.pb(j);
                }
                if (l==1){
                    merge.pb(j);
                    merge.pb(right);
                }
                combinations.pb(merge);
            }
        }
        ll to_add=0;
        fr(len(combinations),b){
            to_add+=freq[combinations[b]];
        }
        ans+=to_add;
        freq[strings[i]]--;
    }
    cout << ans << endl;
}

int main(){
    int t;
    cin >> t;
    while (t--){
        int ll n;
        cin >> n;
        vs strings;
        while (n--){
            string s;
            cin >> s;
            strings.pb(s);
        }
        sol(n,strings);
    }
}