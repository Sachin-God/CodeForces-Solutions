#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define pb push_back
#define FOR(i, s, n) for(int i = s; i < n; i++) // including i is better bcz nested loop will overwrite upper one
#define ROF(i, n, s) for(int i = n; i >= s; --i)
#define FIND(set, target) (set.find(target) != set.end())
#define ent '\n'
#define LSOne(S) ((S) & -(S))

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

template <typename T> 
void print(T x) {cout << x << ent;}

void Solve() {
    int n; cin >> n;
    vvi tree(n, vi());
    vi deg(n, 0);
    int u, v;
    FOR(i, 0, n-1){
        cin >> u >> v;
        u--; v--;
        tree[u].pb(v);
        tree[v].pb(u);
        deg[u]++; deg[v]++;
    }
    if (n <= 2) {
        print(0); return;
    }

    // leafs are the point where a root can atmost extend their route
    // if root have x leaf already then it will only need m - x connection operations
    int total_leafs = 0, root_with_max_no_leaf = 0, curr = 0;
    FOR(i, 0, n) {
        if (deg[i] == 1) total_leafs++;
        for(auto& x : tree[i]) {
            if (deg[x] == 1) curr++;
        }
        root_with_max_no_leaf = max(root_with_max_no_leaf, curr);
        curr = 0;
    }
    print(total_leafs - root_with_max_no_leaf);
}

int main() {
    ios ::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        Solve();               
    }
}