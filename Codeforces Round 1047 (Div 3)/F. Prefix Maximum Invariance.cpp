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

int main() {
    ios ::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vll a(n+1), b(n+1);
        FOR(1, n+1) cin >> a[i];
        FOR(1, n+1) cin >> b[i];
        
        vll pga(n+1, 0), pgb(n+1, 0);
        vll stack;
        FOR(1, n+1) {
            while (!stack.empty() && a[stack.back()] < a[i]) stack.pop_back();
            if (!stack.empty()) {
                pga[i] = stack.back();
                int lo = 0, hi = stack.size() - 1, idx = 0;
                while (lo <= hi) {
                    int mid = (lo + hi) / 2;
                    if (a[stack[mid]] >= b[i]) {
                        idx = stack[mid];
                        lo = mid+1;
                    } else hi = mid - 1;
                }
                pgb[i] = idx;
            }
            stack.pb(i);
        }
        
        ll ans = 0;
    
        FOR(1, n+1) {
            if (a[i] == b[i])
                ans += 1LL * i * (n - i + 1);
            else if (a[i] > b[i])
                ans += 1LL * pga[i] * (n - i + 1);
            else
                ans += 1LL * pgb[i] * (n - i + 1);
        }

        
        cout << ans << '\n';
    }
}