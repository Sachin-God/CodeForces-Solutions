#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define pb push_back
#define f(s, n) for(int i = s; i < n; i++)

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

bool check2026(string& s, int idx) {
    return s[idx] == '2' && s[idx+1] == '0' && s[idx+2] == '2' && s[idx+3] == '6';
}

bool check2025(string& s, int idx) {
    return s[idx] == '2' && s[idx+1] == '0' && s[idx+2] == '2' && s[idx+3] == '5';
}

int main() {
    ios ::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;
        bool is2026 = false;
        bool is2025 = false;
        for (int i = 0; i < n-3; i++) {
            is2026 |= check2026(s, i);
            is2025 |= check2025(s, i);
        }
        if (is2026 || !is2025) cout << 0 << "\n";
        else cout << 1 << "\n";       
    }
}