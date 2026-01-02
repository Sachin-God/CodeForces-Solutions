// 34 minutes
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

int get_k(vll chrs, string word, ll m) {
    for (auto& ch : word) chrs[ch-'A']--;
    vll chr(chrs.begin(), chrs.end());
    FOR(0, 26) chr[i] *= m;
    for (auto& ch : word) {
        chr[ch-'A']--;
        if (chr[ch-'A'] < 0) return -1;
    }
    ll k = INT_MAX;
    FOR(0, 26) {
        if (chrs[i] != 0) k = min(k, chr[i] / chrs[i]);
    }
    return k;
}

int main() {
    ios ::sync_with_stdio(false); cin.tie(nullptr);
    int n; ll m; cin >> n >> m;
    vector<string> a(n);
    FOR(0, n) cin >> a[i];
    vll chrs(26, 0);
    for (auto& x : a) {
        for (auto& ch : x) chrs[ch-'A']++;
    }

    FOR(0, n) cout << get_k(chrs, a[i], m) << " ";
}