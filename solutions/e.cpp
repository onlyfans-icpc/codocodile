#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 1e3 + 5;
const ll oo = 1e18 + 5;
int n, m;
ll a[N][N];
ll maxsum, ans, e[N][N], s[N][N];

void Main() {
    ans = -oo;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j];
    for(int col = 0; col < m; col++) {
        e[0][col] = a[0][col];
        for(int row = 1; row < n; row++)
            e[row][col] = max(e[row - 1][col] + a[row][col], a[row][col]);

        s[n - 1][col] = a[n - 1][col];
        for(int row = n - 2; row >= 0; row--)
            s[row][col] = max(s[row + 1][col] + a[row][col], a[row][col]);
    }

    for(int row = 0; row < n; row++) {
        maxsum = -oo;
        for(int col = 0; col < m; col++) {
            maxsum = max(maxsum + a[row][col], a[row][col]);
            ans = max(ans, maxsum + max(e[row][col], s[row][col]) - a[row][col]);
        }
        maxsum = -oo;
        for(int col = m - 1; col >= 0; col--) {
            maxsum = max(maxsum + a[row][col], a[row][col]);
            ans = max(ans, maxsum + max(e[row][col], s[row][col]) - a[row][col]);
        }
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    Main();
    return 0;
}