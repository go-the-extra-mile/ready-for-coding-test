#include <iostream>
#include <limits>

using namespace std;

const int INF = 1'000'000'000;

typedef long long ll;

ll combi[201][101];

ll combination(int n, int r) {
    ll &ret = combi[n][r];
    if (n == r || r == 0) return ret = 1;
    if (ret != 0) return ret;

    ll result = combination(n-1, r) + combination(n-1, r-1);
    if (result > INF) return ret = INF;
    return ret = result;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m, k;
    cin >> n >> m >> k;
    
    if (combination(n+m, n) < k) {
        cout << -1 << '\n';
        return 0;
    }
    while(1) {
        if (n == 0) {
            while(m--) cout << 'z';
            break;
        }
        if (m == 0) {
            while(n--) cout << 'a';
            break;
        }
        
        int starts_with_a = combination(n+m-1, m);
        if (starts_with_a < k) { // 'z' if (n+m-1)C(m) < k
            cout << 'z';
            k -= starts_with_a;
            m--;
        }
        else { // 'a'
            cout << 'a';
            n--;
        }
    }

    return 0;
}