#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define pb push_back
#define FOR(s, n) for(int i = s; i < n; i++)

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;

template <typename T>
void print_vector(const vector<T>& vec) {
    for (const auto& x : vec) cout << x << ' ';
    cout << '\n';
}

template <typename T>
void print_grid(const vector<vector<T>>& grid) {
    for (const auto& row : grid) {
        for (const auto& elem : row) {
            cout << elem << " ";
        }
        cout << '\n';
    }
}

bool isvalid(const vi& b, const vi& c, const int& n, int k) {
    FOR(0, n) {
        if (b[i] >= c[(k+i) % n]) return false;
    }
    return true;
}

int main() {
    ios ::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vi a(n), b(n), c(n);
        FOR(0, n) cin >> a[i];
        FOR(0, n) cin >> b[i];
        FOR(0, n) cin >> c[i];

        vvi g(n, vi(n, 0));
        vi idx(n, 0);

        for (int k = 0; k < n; k++) {
            if (isvalid(b, c, n, k)) {
                for (int j = 0; j < n; j++) {
                    g[j][(k+j) % n] = 1;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                idx[i] += g[i][j];
            }
        }

        long long ans = 0;
        for (int j = 0; j < n; j++) {
            if (isvalid(a, b, n, j)) {
                for (int i = 0; i < n; i++) {
                    ans += idx[i];
                }
            }
        }

        cout << ans << "\n";
    }
}