#include <bits/stdc++.h>
#define fr(size, i) for (int i=0; i<size; i++)
#define len(arr) arr.size()
using namespace std;


/**
Consider a problem where our task is to process k jobs using n machines.
Each machine i is assigned an integer pi: the time to process a single job.
What is the minimum time to process all the jobs?
 **/

int sum(vector<int> p, int x){
    int sum=0;
    fr(p.size(),i){
        sum+=x/p[i];
    }
    return sum;
}

void sol(vector<int> p, int k){
    int L = 1;
    std::sort(p.begin(), p.end());
    int R = p[len(p)-1]*k;
    int x;
    while(L<=R){
        x = (L+R)/2;
        int suma = sum(p,x);
        if (suma==k){
            break;
        }
        if (suma<k){
            L=x+1;
        }else{
            R=x-1;
        }
    }
    cout << x <<  endl;
}

int main(){
    vector<int> p = {2,5,3,2};
    int k=9;
    sol(p,k);
    return 0;
}