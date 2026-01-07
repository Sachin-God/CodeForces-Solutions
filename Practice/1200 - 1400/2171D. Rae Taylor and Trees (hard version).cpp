// 20 mins 
// prev submission comments are wrong - this is wholly done by me
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

int find(int x, vi& parent) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x], parent);
}

void Union(int x, int y, vi& parent, vi& rank) {
    int px = find(x, parent), py = find(y, parent);
    int rx = rank[px], ry = rank[py];
    if (px == py) return;
    if (rx > ry) parent[py] = parent[px];
    else if (rx < ry) parent[px] = parent[py];
    else {
        parent[py] = parent[px];
        rank[px]++;
    }
}

int main() {
    ios ::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vi a(n);
        FOR(i, 0, n) cin >> a[i];
        vi pre(n), suff(n);
        pre[0] = a[0]; suff[n-1] = a[n-1];

        FOR(i, 1, n) pre[i] = min(pre[i-1], a[i]);
        bool valid = true;
        ROF(i, n-2, 0) {
            suff[i] = max(suff[i+1], a[i]);
            if (pre[i] > suff[i+1]) valid = false;
        }

        if (valid) {
            cout << "Yes" << "\n";
            vvi edges;
            FOR(i, 1, n) {
                if (pre[i] != pre[i-1]) edges.pb({suff[i], pre[i-1]});
                else edges.pb({a[i], pre[i]});
            }
            print_grid(edges);
        }
        else cout << "No";
        cout << "\n";
    }
}