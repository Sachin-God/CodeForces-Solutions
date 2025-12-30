#include <bits/stdc++.h>
using namespace std;
#define all(x) begin(x), end(x)
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;
#define f(s, n) for(int i = s; i < n; i++)

int main() {
    ios ::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vi b(n);
        int min_elem = INT_MAX;
        f(0, n) {cin >> b[i]; min_elem = min(min_elem, b[i]);}
        bool found = false, valid = true;
        f(0, n) {
            if (b[i] == min_elem) found = true;
            if (found && b[i] > min_elem) {valid = false; break;}
        }

        if (valid) cout << "yes\n";
        else cout << "no\n";
    }
}