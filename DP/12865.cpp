/*
무게와 가치가 있는 물건들이 있을 때, 무게제한이 있는 가방에 가장 가치의 합이 크도록 담는
0-1 Knapsack 문제이다. 다음과 같은 점화식을 세워 풀 수 있다고 생각했다. 

max_value(start, left)를 다음과 같이 정의한다. 
    : 물건 인덱스 start ~ (N-1), 가방의 남은 용량이 left일 때 담기는 가치의 최대값

그러면 max_value(start, left)는 더 작은 부분 문제로 쪼개어 표현할 수 있다. 
max_value(start, left)
    = {
        max {
            value(start) + max_value(start + 1, left - weight(start)) (if left >= weight(start)), 
            max_value(start + 1, left)
        } (if start != N), 
        0 (if start == N)
    }
    
*/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N_MAX = 100;
const int K_MAX = 100'000;
const int W_MAX = 100'000;
const int V_MAX = 1'000;

int n, k;
int weight[W_MAX];
int value[V_MAX];

int cache[N_MAX][K_MAX]; 

int max_value(int start, int left) { 
    if (start == n) return 0;
    int& res = cache[start][left];
    if (res != -1) return res;

    int mx = 0;
    if (left >= weight[start]) mx = value[start] + max_value(start + 1, left - weight[start]);
    mx = max(mx, max_value(start + 1, left));

    return res = mx;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> weight[i] >> value[i];
    }

    memset(cache, -1, sizeof(cache));
    cout << max_value(0, k) << '\n';

    return 0;
}