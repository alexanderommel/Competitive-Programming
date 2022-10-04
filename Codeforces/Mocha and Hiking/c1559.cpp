#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <sstream>
using namespace std;

string sol(int n,vector<int> A){
    bool terminalFound=false;
    int i = 0;
    int c = 1;
    vector<int> path;
    for (;i<A.size();i++){
        if(i==0 and A[0]==1){
            path.push_back(n+1);
            terminalFound=true;
        }
        path.push_back(c);
        if (terminalFound==true){
            c++;
            continue;
        }

        if(A[i]==0){
            if(c==n){
                path.push_back(n+1);
                break;
            }
            if (A[i+1]==1){
                path.push_back(n+1);
                terminalFound=true;
            }
        }
        c++;
    }
    if(path.size()!=n+1){
        return "-1";
    }
    stringstream  ss;
    for (size_t i=0;i<path.size();i++){
        if(i!=0)
            ss<<" ";
        ss << path[i];
    }
    return ss.str();
}

int main() {
    int t =0;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        string S;
        string delimiter=" ";
        cin.ignore();
        getline(cin,S,'\n');
        size_t p=0;
        string token;
        vector<int> A;
        while ((p=S.find(delimiter)) != std::string::npos){
            token = S.substr(0,p);
            A.push_back(stoi(token));
            S.erase(0,p + delimiter.length());
        }
        A.push_back(stoi(S));
        cout<<sol(n,A)<<"\n";
    }
    return 0;
}