// 42 minutes
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
typedef vector<string> vs;

template <typename T> using maxHeap = priority_queue<T>;
template <typename T> using minHeap = priority_queue<T, vector<T>, greater<T>>;

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
        vll even; ll odd = 0, temp;
        int count = 0;
        FOR(0, n) {
            cin >> temp;
            if (temp % 2 == 0) even.pb(temp);
            else {odd = max(odd, temp); count++;}
        }
        sort(all(even));
        vll ps = {0};
        int m = even.size();
        FOR(0, m) ps.pb(ps[i] + even[i]);

        FOR(0, n) {
            if (odd == 0 || (even.size() == 0 && i % 2 == 1)) cout << 0 << " ";
            else {
                ll res = odd;
                if (i <= m) res += ps[m] - ps[m-i];
                else {
                    int remaining = i-m;
                    if (remaining % 2 == 1) remaining++;
                    res += ps[m] - ps[m-i+remaining];
                    if (remaining == count) res = 0;
                }
                cout << res << " ";
            }
        }
        cout << "\n";
    }
}