#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define pb push_back
#define FOR(i, s, n) for(int i = s; i < n; i++) // including i is better bcz nested loop will overwrite upper one
#define ROF(i, n, s) for(int i = n; i >= s; --i)

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

void permutation(int idx, int n, vs& perm, string p, vb& visited) {
    if (idx == n) {
        perm.pb(p);
        return;
    }
    
    FOR(i, 0, n) {
        if (visited[i]) continue;
        visited[i] = true;
        p += char(i+'1');
        permutation(idx+1, n, perm, p, visited);
        p.pop_back();
        visited[i] = false;
    }
}

pii find(string& x, string& y, int n) {
    int a = 0;
    FOR(i, 0, n) {
        if (x[i] == y[i]) a++;
    }
    return {a,n-a};
}

int main() {
    ios ::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        int n = s.length();
        int j, k; cin >> j >> k;
        vs perm;
        vb temp(n, false);
        permutation(0, n, perm, "", temp);
        
        pii ans = find(perm[j-1], perm[k-1], n);
        cout << ans.first << 'A' << ans.second << 'B' << '\n';
    }
}