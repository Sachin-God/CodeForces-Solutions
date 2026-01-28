#include <bits/stdc++.h>
using namespace std;
#define all(x) begin(x), end(x)
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;
#define f(s, n) for (int i = s; i < n; i++)

const int _N = 1e5 + 5;

int T;

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        ll mn1 = LLONG_MAX, mn2 = LLONG_MAX;
        f(0,n) {
            ll x, y;
            cin >> x >> y;
            mn1 = min(mn1, x - y);
            mn2 = min(mn2, x + y);
        }
        ll res;
        cout << "? L 1000000000" << endl;
        cin >> res;
        cout << "? L 1000000000" << endl;
        cin >> res;
        cout << "? U 1000000000" << endl;
        cin >> res;
        cout << "? U 1000000000" << endl;
        cin >> res;
        ll eq1 = res - mn1 - 4000000000ll;
        cout << "? D 1000000000" << endl;
        cin >> res;
        cout << "? D 1000000000" << endl;
        cin >> res;
        cout << "? D 1000000000" << endl;
        cin >> res;
        cout << "? D 1000000000" << endl;
        cin >> res;
        ll eq2 = mn2 - res + 4000000000ll;
        cout << "! " << (eq2 - eq1) / 2 << ' ' << (eq2 + eq1) / 2 << endl;
    }
}