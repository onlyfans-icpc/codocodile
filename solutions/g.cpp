#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> scores(n);

    for (int i = 0; i < n; i++) {
        cin >> scores[i];
    }

    long long medianSum = 0;

    for (int len = 1; len <= n; len++) {
        for (int l = 0; l + len <= n; l++) {
            int r = l + len - 1;
            vector<int> subarray(scores.begin() + l, scores.begin() + r + 1);
            sort(subarray.begin(), subarray.end());
            int median = subarray[subarray.size() / 2];
            medianSum += median;
        }
    }

    cout << medianSum << endl;
    return 0;
}
