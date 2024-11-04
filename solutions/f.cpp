#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 1e5 + 5;
int n;
ll counter[N];
pair<ll, ll> a[N];

bool compare(pair<ll, ll> &a, pair<ll, ll> &b) {
    if(a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}

void Main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i + 1;
    }
    if(n == 1) {
        cout << a[0].first << endl;
        return;
    }
    sort(a, a + n, compare);

    int start = 0, cur = 1;
    a[n].first = 0;
    while(cur <= n) {
        while(cur < n && a[start].second < a[cur].second) cur++;
        counter[a[start].second - 1] += (a[start].first - a[cur].first) * (start + 1);
        for(int i = start + 1; i < cur; i++) {
            counter[a[start].second - 1] += a[i].first - a[cur].first;
        }
        start = cur;
        cur++;
    }
    
    for(int i = 0; i < n; i++)
        cout << counter[i] << '\n';
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    Main();
    return 0;
}

