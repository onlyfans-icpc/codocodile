#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 1e5 + 5;
int n;
string str;
string codocodile = "codocodile";
string corocodile = "corocodile";
bool match;

void Main() {
    cin >> str;
    for(int i = 0; str[i + corocodile.size() - 1]; i++) {
        match = true;
        for(int j = 0; corocodile[j]; j++) {
            if(str[i + j] != corocodile[j]) {
                match = false;
                break;
            }
        }
        if(match) {
            str[i + 2] = 'd';
        }
    }
    cout << str << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    Main();
    return 0;
}