/*
    두 문자열의 LCS 길이 문제를 푸는 방식부터 알아보자. 두 문자열 A, B의 LCS 길이를 구하는 문제는 
    각 문자열의 prefix의 LCS 길이를 구하는 문제, 즉 부분문제의 답으로 구해낼 수 있다. 
    LCS(i, j)를 A의 prefix A[0:i]와 B의 prefix B[0:j]의 LCS 길이라고 정의하자. 
    A[i-1]과 B[j-1]이 일치한다면 A[0:i-1]과 B[0:j-1]의 LCS 길이에 새로 발견한 일치하는 문자 A[i-1]을 더한 것이 
    LCS가 된다. 
    만약 일치하지 않는다면, A[0:i]와 B[0:j-1]의 LCS가 곧 이 문제의 LCS거나, A[0:i-1]과 B[0:j]의 LCS가 이 문제의 LCS다. 
    가장 긴 것을 구하고 있으므로, 둘 중 긴 것이 이 문제의 LCS가 된다. 

    이를 점화식으로 써보면 다음과 같다. 
    LCS(i, j) = {
        LCS(i-1, j-1) + 1               (A[i-1] == B[j-1]일 때)
        max(LCS(i, j-1), LCS(i-1, j))   (A[i-1] != B[j-1]일 때)
        0                               (i 또는 j가 0일 때)
    }

    이제 이것을 세 문자열의 LCS 길이 문제로 확대해보자. 
    문자열 A, B, C의 LCS 길이 문제 역시 부분문제의 답으로 구해낼 수 있다. 
    LCS(i, j, k)를 A[0:i], B[0:j], C[0:k]의 LCS 길이라고 정의하자. 
    각 부분문자열의 마지막 글자가 일치한다면 A[0:i-1], B[0:j-1], C[0:k-1]의 LCS 길이에 일치하는 문자를 하나 더한 것이 
    LCS가 된다. 
    나머지 경우로는 두 글자는 일치하는데 하나는 일치하지 않는 경우, 그리고 세 글자 모두 일치하지 않는 경우가 있다. 
    1.  두 글자는 일치하는데 하나는 일치하지 않는 경우 
        대표적인 경우로 A[i-1] == B[j-1] != C[k-1]이라고 하자. 
        이 조건을 한꺼번에 생각하기가 어려워 조건을 세 개로 쪼갰다. 
        (1) A[i-1] == B[j-1]
        (2) A[i-1] != C[k-1]
        (3) B[j-1] != C[k-1]
        먼저 (1)에 따라 LCS(i-1, j-1, k) + 1을 고려할까 생각하게 되는데 (2)를 동시에 만족해야 하므로 고려하지 않아도 된다는 것을 알게 된다. 
        (2)에 따라 LCS(i-1, j, k), LCS(i, j, k-1)을 고려해야 된다는 것을 알게 된다. 
        (3)에 따라 LCS(i, j-1, k), LCS(i, j, k-1)을 고려해야 된다는 것을 알게 된다. 
        (1), (2), (3)을 다 만족하는 LCS 길이는 결국 고려하는 네 가지 값의 최대값이 된다. 
        그런데 네 가지 값 중 겹치는걸 제외하면 세 가지 값이 남는다. 
    
    2.  세 글자 모두 일치하지 않는 경우
        이번에도 조건을 세 가지로 쪼개봤다. 
        (1) A[i-1] != B[j-1]
        (2) A[i-1] != C[k-1]
        (3) B[j-1] != C[k-1]
        (1)에 따라 LCS(i-1, j, k), LCS(i, j-1, k)를 고려해야 된다는 것을 알게 된다. 
        (2), (3)은 위에서 말한 네 가지를 고려해야 된다. 
        (1), (2), (3)을 다 만족하는 LCS 길이는 결국 고려하는 여섯 가지 값의 최대값이 된다. 
        여기서도 겹치는 값을 제외하면 세 가지 값이 남는다. 
    
    1, 2 두 경우 모두 max(LCS(i-1, j, k), LCS(i, j-1, k), LCS(i, j, k-1))이 답이다. 

    이를 점화식으로 쓰면 다음과 같다. 
    LCS(i, j, k) = {
        LCS(i-1, j-1, k-1) + 1                              (A[i-1], B[j-1], C[k-1]이 모두 일치하는 경우)
        max(LCS(i-1, j, k), LCS(i, j-1, k), LCS(i, j, k-1)) (나머지 경우)
        0                                                   (i나 j나 k가 0인 경우)
    }

*/
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

const int N_MAX = 100;
int cache[N_MAX+1][N_MAX+1][N_MAX+1];
// cache[i][j][k]: a[0:i], b[0:j], c[0:k]의 LCS 길이

string a, b, c;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    memset(cache, -1, sizeof(cache));

    cin >> a >> b >> c;

    for (int i = 0; i <= a.length(); i++) {
        for (int j = 0; j <= b.length(); j++) {
            for (int k = 0; k <= c.length(); k++){
                if (i == 0 || j == 0 || k == 0) {
                    cache[i][j][k] = 0;
                    continue;
                }

                if (a[i-1] == b[j-1] && b[j-1]== c[k-1]) {
                    cache[i][j][k] = cache[i-1][j-1][k-1] + 1;
                }
                else {
                    cache[i][j][k] = max({cache[i-1][j][k], cache[i][j-1][k], cache[i][j][k-1]});
                }
            }
        }
    }

    cout << cache[a.length()][b.length()][c.length()] << '\n';

    return 0;
}