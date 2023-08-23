#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

const int N_MAX = 100;
int cache[N_MAX+1][N_MAX+1][N_MAX+1];

string a, b, c;

// lcs(i, j, k): a[0, i), b[0, j), c[0, k)의 LCS 길이
int lcs(int i, int j, int k){ 
    auto& ret = cache[i][j][k];
    if (ret != -1) return ret;

    if (i == 0 || j == 0 || k == 0) return ret = 0;

    if (a[i-1] == b[j-1] && b[j-1] == c[k-1]) return ret = lcs(i-1, j-1, k-1) + 1;
    else  return ret = max({lcs(i-1, j, k), lcs(i, j-1, k), lcs(i, j, k-1)});
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    memset(cache, -1, sizeof(cache));

    cin >> a >> b >> c;

    cout << lcs(a.length(), b.length(), c.length()) << '\n';

    return 0;
}