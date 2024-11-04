#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 1e5 + 5;
const ll M = 1e9 + 7;
ll fact[N], inv[N];

ll exp(ll b, ll e, ll m) {
    ll result = 1;
    b = b % m;
    while(e) {
        if(e % 2)
            result = result * b % m;
        b = b * b % m;
        e /= 2;
    }
    return result;
}

void preProcess() {
    fact[0] = 1;
    for(int i = 1; i < N; i++)
        fact[i] = fact[i - 1] * i % M;
    inv[N - 1] = exp(fact[N - 1], M - 2, M);
    for(int i = N - 1; i > 0; i--)
        inv[i - 1] = inv[i] * i % M;
}

ll combination(int n, int r) {
    if(r < 0 || r > n) return 0;
    return fact[n] * inv[r] % M * inv[n - r] % M;
}

int main() {
    preProcess();
    int n, k;
    cin >> n >> k;
    cout << combination(n, k % n) << endl;
    return 0;
}
