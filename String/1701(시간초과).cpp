#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> get_pi(string pat) {
    vector<int> pi(pat.length(), 0);

    int j = 0; // 일치 확인을 시작하는 인덱스
    for (int i = 1; i < pat.length(); i++) {
        // get pi[i]
        while (j > 0 && pat[i] != pat[j]) {
            j = pi[j-1];
        }
        if (pat[i] == pat[j]) {
            pi[i] = ++j;
        }
        else {
            pi[i] = 0;
        }
    }

    return pi;
}

bool kmp_twice(string str, string pat) {
    int cnt = 0;

    const auto& pi = get_pi(pat);
    int j = 0;
    for (int i = 0; i < str.length(); i++) {
        while (j > 0 && str[i] != pat[j]) {
            j = pi[j-1];
        }
        if (str[i] == pat[j]) {
            if (j == pat.length() - 1) {
                if (++cnt >= 2) return true;
                j = pi[j];
            }
            else {
                j++;
            }
        }
    }

    return false;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    string str;
    cin >> str;

    int res;
    for (res = str.length() - 1; res > 0; res--) {
        for (int i = 0; i < str.length() - res + 1; i++) {
            string pat = str.substr(i, res);

            if (kmp_twice(str, pat)) {
                cout << pat.length() << '\n';
                return 0;
            }
        }
    }

    cout << res << '\n';

    return 0;
}