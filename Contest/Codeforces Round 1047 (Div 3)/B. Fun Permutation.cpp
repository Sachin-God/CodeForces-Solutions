#include <bits/stdc++.h>
using namespace std;

// way 1 idea is that i + n - i == n which will be greater for n >= 2
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> p(n);
        for (int i = 0; i < n; i++) cin >> p[i];
        for (int i = 0; i < n; i++) cout << n - p[i] + 1 << " ";
            
        cout << "\n";
    }

    return 0;
}

// way 2
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> p(n);
        for (int i = 0; i < n; i++) cin >> p[i];
        for (int i = 3; i <= 100; i++) {
            if (n % i == 0 || n%i == i-1) {
                for (int x = 0; x < n; x++) {
                    int k = p[x] / i;
                    cout << k*i + (i - (p[x] % i)) % i << " ";
                }
                break;
            }
        }
            
        cout << "\n";
    }

    return 0;
}