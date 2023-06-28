#include <bits/stdc++.h>
using namespace std;

/** Si k=30, y n=14, entonces ans=10**/
long long divisor_of_k_lower_equal_than_n(long long N, long long K)
{
    long long rem = N % K;

    if (rem == 0)
        return N;
    else
        return N - rem;
}