// 36 mins
#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define pb push_back
#define FOR(s, n) for(int i = s; i < n; i++)
#define ROF(n, s) for(int i = n; i >= s; --i)

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

int bs(const vi& a, int& t) {
    int lo = 0, hi = a.size()-1, idx = 0;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (a[mid] >= t) {
            idx = mid;
            hi = mid-1;
        } else lo = mid+1;
    }
    return idx;
}

int main() {
    ios ::sync_with_stdio(false); cin.tie(nullptr);
    int n, t; cin >> n >> t;
    vi a(n), ps = {0};
    FOR(0, n) cin >> a[i];
    // generating a prefix sum array
    FOR(0, n) ps.pb(a[i] + ps[i]);
    int ans = 0;
    FOR(1, n+1) {
        int rem = ps[i] - t;
        int idx = bs(ps, rem);
        ans = max(ans, i - idx);
    }
    cout << ans << "\n";
}