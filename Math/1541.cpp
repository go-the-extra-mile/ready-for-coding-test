/* 
    -와 - 사이를 괄호로 묶는다
    = - 다음에 오는 모든 연달은 +를 -라 본다
    = -가 나온 순간부터 모든 연산자를 -라 본다
 */

#include <iostream>
#include <string>

using namespace std;

int main(){
    string line;
    cin >> line;

    int ans = 0;
    bool met_minus = false;

    string num_str;
    int cur_num;
    for (int i=0; i < line.length(); i++){
        if ('0' <= line[i] && line[i] <= '9'){
            num_str += line[i];
            continue;
        }

        cur_num = stoi(num_str);
        num_str.clear();
        
        if (met_minus) {
            ans -= cur_num;
        }
        else {
            ans += cur_num;
            if (line[i] == '-') met_minus = true;
        }
    }

    cur_num = stoi(num_str);
    if (met_minus) ans -= cur_num;
    else ans += cur_num;

    cout << ans << '\n';
}