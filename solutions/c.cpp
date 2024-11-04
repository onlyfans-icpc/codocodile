#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 1e5 + 5;
const int oo = 1e9;
int n, a[N], nums[N], maximum = -oo, ans = 0;

void Main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        maximum = max(maximum, a[i]);
        nums[a[i]]++;
        nums[a[i] + 1]++;
        if(a[i] - 1 >= 0) nums[a[i] - 1]++;
    }
    for(int i = 0; i <= maximum; i++)
        ans = max(ans, nums[i]);
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    Main();
    return 0;
}