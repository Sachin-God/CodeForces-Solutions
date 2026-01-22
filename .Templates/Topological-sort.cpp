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

// Only works for DAG
void kahn_topo_sort(vpi& edges,vi& topo_sort, int n) {
    umap<int, vi> graph; 
    vi degree(n+1, 0);
    for(auto& e : edges) {
        graph[e.first].pb(e.second);
        degree[e.second]++;
    }
    qi q;
    FOR(i, 1, n+1) {
        if (!degree[i]) q.push(i);
    }

    while (!q.empty()) {
        int u = q.front(); q.pop();
        topo_sort.pb(u);

        for (auto& x : graph[u]) {
            degree[x]--;
            if (degree[x] == 0) q.push(x);
        }
    }

    if (topo_sort.size() != n) cout << "Neg cycle" << ent;
}