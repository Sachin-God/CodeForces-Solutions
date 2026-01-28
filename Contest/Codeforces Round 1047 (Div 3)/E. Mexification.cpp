#include <bits/stdc++.h>
using namespace std;
#define all(x) begin(x), end(x)
typedef long long ll;

ll calculateMex(vector<ll>& a) {
    int n = a.size();
    vector<bool> b(n+1, false);
    ll mex = 0;
    for (auto& x : a) {
        b[x] = true;
        while (mex <= n && b[mex]) mex++;
    }
    return mex;
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<ll> a(n), f(n+1, 0);

        for (int i = 0; i < n; i++) {cin >> a[i]; f[a[i]]++;}

        k--; ll mex = calculateMex(a);
        for (int i = 0; i < n; i++) {
            if (a[i] > mex || f[a[i]] > 1) a[i] = mex;
        }

        if (k > 0) {
            f.clear();
            f.resize(n+1, 0);
            k--; mex = calculateMex(a);
            for (int i = 0; i < n; i++) f[a[i]]++;
            for (int i = 0; i < n; i++) {
                if (a[i] > mex || f[a[i]] > 1) a[i] = mex;
            }
        }

        if (k > 0) {
            f.clear();
            f.resize(n+1, 0);
            if (k % 2 == 1) mex = calculateMex(a);
            for (int i = 0; i < n; i++) f[a[i]]++;
            for (int i = 0; i < n; i++) {
                if (a[i] > mex || f[a[i]] > 1) {
                    a[i] = mex;
                }
            }
        }

        ll ans = 0;
        
        for (int i = 0; i < n; i++) ans += a[i];
        cout << ans << "\n";
    }
}