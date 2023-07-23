#include <iostream>
#include <algorithm>

using namespace std;

const int N_MAX = 1000;
// costs
int R[N_MAX];
int G[N_MAX];
int B[N_MAX];

int R_min[N_MAX]; // R_min[i]: 1~(i-1)번 집을 칠하고, i번 집을 빨간색으로 칠하는데 드는 최소 비용
int G_min[N_MAX];
int B_min[N_MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> R[i] >> G[i] >> B[i];
        if (i == 0) {
            R_min[i] = R[i];
            G_min[i] = G[i];
            B_min[i] = B[i];
            continue;
        }

        R_min[i] = min(B_min[i-1], G_min[i-1]) + R[i];
        G_min[i] = min(R_min[i-1], B_min[i-1]) + G[i];
        B_min[i] = min(R_min[i-1], G_min[i-1]) + B[i];
    }

    cout << min({R_min[n-1], G_min[n-1], B_min[n-1]}) << '\n';

    return 0;
}