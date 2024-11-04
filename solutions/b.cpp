#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 1e5 + 5;
int x, y, ans, temp;

void Main() {
    cin >> x >> y;
    temp = max(999 - x, y - 100);
    ans = x - y;
    if(temp / 100) ans += temp / 100 * 100;
    else if(temp / 10 % 10) ans += temp / 10 % 10 * 10;
    else ans += temp % 10;

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    Main();
    return 0;
}