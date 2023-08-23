#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int get_max_pi(string pat) {
    int res = 0;

    vector<int> pi(pat.length(), 0);

    int j = 0; // 일치 확인을 시작하는 인덱스
    for (int i = 1; i < pat.length(); i++) {
        // get pi[i]
        while (j > 0 && pat[i] != pat[j]) {
            j = pi[j-1];
        }
        if (pat[i] == pat[j]) {
            pi[i] = ++j;
            res = max(res, pi[i]);
        }
        else {
            pi[i] = 0;
        }
    }

    return res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    string str;
    cin >> str;

    int res = 0;
    for (int i = 0; i < str.length(); i++) {
        string substr = str.substr(i);
        auto mx = get_max_pi(substr);
        res = max(res, mx);
    }

    cout << res << '\n';

    return 0;
}