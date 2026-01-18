// prev day - read editorial for DS hint otherwise 80% solved by myself
// 21 minutes
#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define pb push_back
#define FOR(i, s, n) for(int i = s; i < n; i++) // including i is better bcz nested loop will overwrite upper one
#define ROF(i, n, s) for(int i = n; i >= s; --i)
#define FIND(set, target) (set.find(target) != set.end())

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
typedef pair<string, string> pss;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;
typedef vector<string> vs;
typedef vector<pii> vpi;
typedef vector<pll> vpll;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;

typedef deque<int> dqi;
typedef deque<ll> dqll;
typedef deque<pii> dqii;
typedef deque<string> dqs;

typedef queue<int> qi;
typedef queue<ll> qll;
typedef queue<pii> qii;
typedef queue<string> qs;

template <typename T> using maxHeap = priority_queue<T>;
template <typename T> using minHeap = priority_queue<T, vector<T>, greater<T>>;
template <typename S, typename T> using umap = unordered_map<S, T>;
template <typename T> using uset = unordered_set<T>;

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

void Solve() {
    int n, q; cin >> n >> q;
    vvi elemFreq(2, vi(n+1, 0));
    vi adj_diff(n+1, 0), a(n);
    FOR(i, 0, n) {
        cin >> a[i];
        elemFreq[0][i+1] += elemFreq[0][i];
        elemFreq[1][i+1] += elemFreq[1][i];
        elemFreq[a[i]][i+1]++;

        if (i > 0) adj_diff[i+1] += adj_diff[i] + abs(a[i]-a[i-1]);
    }

    int l, r, o, z, ans;
    FOR(i, 0, q) {
        cin >> l >> r;
        z = elemFreq[0][r] - elemFreq[0][l-1];
        o = elemFreq[1][r] - elemFreq[1][l-1];
        if (o % 3 != 0 || z % 3 != 0) cout << -1 << '\n';
        else {
            ans = o / 3 + z / 3;
            if (adj_diff[r] - adj_diff[l] == r-l) ans++;
            cout << ans << '\n';
        }
    }
}

int main() {
    ios ::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        Solve();               
    }
}