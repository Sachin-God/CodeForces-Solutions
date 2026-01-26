#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define pb push_back
#define FOR(i, s, n) for(int i = s; i < n; i++) // including i is better bcz nested loop will overwrite upper one
#define ROF(i, n, s) for(int i = n; i >= s; --i)
#define FIND(set, target) (set.find(target) != set.end())
#define ent '\n'

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

void Solve() {  // O(n * √n * logn)
    int n, t; cin >> n;
    set<int> s;
    FOR(i, 0, n) {cin >> t; s.insert(t);}
    vi ans(n+1, -1);
    FOR(i, 1, n+1) {
        if (FIND(s, i)) ans[i] = 1; // O(logn)
        else {
            int best = INT_MAX;
            int root = pow(i, 0.5) + 1;
            FOR(k, 1, root) { // O(√n)
                if (i % k == 0 && ans[k] != -1 && ans[i/k] != -1) {
                    best = min(best, ans[k]+ans[i/k]);
                }
            }
            ans[i] = (best != INT_MAX ? best : -1);
        }
    }
    FOR(i, 1, n+1) cout << ans[i] << ' ';
    cout << ent;
}

int main() {
    ios ::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        Solve();               
    }
}