#include <iostream>
#include <string>

using namespace std;

string s, bomb;
string res; // 결과가 될 문자열

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> s;
    cin >> bomb;

    for (int i = 0; i < s.length(); i++) {
        res += s[i]; // 일단 res에 추가

        if (res.length() >= bomb.length()) { 
            // res의 마지막 len(bomb) 개 글자와 bomb이 일치하는지 맨 뒷 글자부터 확인한다
            int k = res.length() - 1;
            int l = bomb.length() - 1;

            while (k >= 0 && l >= 0) {
                if (res[k] != bomb[l]) break;
                k--; l--;
            }

            if (l < 0) { // res의 마지막 len(bomb)개 글자들과 bomb이 일치했다
                res.erase(end(res) - bomb.length(), end(res)); // res의 마지막 len(bomb)개 글자를 폭발시킨다
            }
        }
    }
    
    if (res.empty()) cout << "FRULA\n";
    else cout << res << '\n';

    return 0;
}