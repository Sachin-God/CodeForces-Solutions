// 40 mins

#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define pb push_back
#define FOR(i, s, n) for(int i = s; i < n; i++) // including i is better bcz nested loop will overwrite upper one
#define ROF(i, n, s) for(int i = n; i >= s; --i)

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;
typedef vector<string> vs;
typedef vector<pair<int, int>> vpi;
typedef vector<pair<ll, ll>> vpll;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;

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

// wrong solution
int Initially_what_i_thought() {
    ios ::sync_with_stdio(false); cin.tie(nullptr);
    int n, m, k; cin >> n >> m >> k;
    vi prod(n);
    FOR(i, 0, n) cin >> prod[i];

    int u, v;
    deque<pair<int, int>> route;
    FOR(i, 0, m) {
        cin >> u >> v;
        route.pb({min(u, v), max(u, v)});
    }

    sort(all(route));
    vi dis(n, 1e6);
    dis[0] = 0;
    while (!route.empty()) {
        auto r = route.front(); route.pop_front();
        int x = r.first;
        int y = r.second;
        x--; y--;
        dis[y] = min(dis[x]+1, dis[y]);
        dis[x] = min(dis[y]+1, dis[x]);
        if (dis[y] == 1e6 || dis[x] == 1e6) route.pb(r);
    }

    vi dist(k, 0);
    FOR(i, 0, n) {
        dist[prod[i]-1] = max(dist[prod[i]-1], dis[i]);
    }
    print_vector(dist);
}

int main() {
    ios ::sync_with_stdio(false); cin.tie(nullptr);
    int n, m, k; cin >> n >> m >> k;
    vi product(n+1);
    FOR(i, 1, n+1) cin >> product[i];

    int u, v;
    vvi graph(n+1);
    FOR(i, 0, m) {
        cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
    }

    queue<int> q;
    q.push(1);
    vb visited(n+1, false);
    vi dis(n+1, INT_MAX);
    dis[1] = 0;
    while (!q.empty()) {
        int x = q.front(); q.pop();
        for (auto& y : graph[x]) {
            if (dis[x]+1 < dis[y]) {
                dis[y] = dis[x]+1;
                q.push(y);
            }
        }
    }

    vi cost(k, 0);
    FOR(i, 0, n) {
        cost[product[i+1]-1] = max(cost[product[i+1]-1], dis[i+1]);
    }
    print_vector(cost);
}