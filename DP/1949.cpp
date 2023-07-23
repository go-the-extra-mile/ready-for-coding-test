/*
문제 풀이를 잘못 생각해 오래 걸린 문제

점화식을 다음과 같이 잘못 세웠다. 
good_residents(i, 0) = max{good_residents(j, 0), good_residents(j, 1)} for j in children(i)
good_residents(i, 1) = residents(i) + max{good_residents(j, 0)} for j in children(i)

옳은 점화식은 다음과 같다. 
good_residents(i, 0) = sum{ max{good_residents(j, 0), good_residents(j, 1)} for j in children(i) }
good_residents(i, 1) = residents(i) + sum{ good_residents(j, 0) for j in children(i) }

*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long ll;

const int MAX_TOWNS = 10'000;
int n;
vector<int> tree[MAX_TOWNS + 1];
short residents[MAX_TOWNS + 1];
ll cache[MAX_TOWNS + 1][2]; 
// cache[t][0]: t가 비우수마을일 때, 마을 t를 루트로 가지는 tree의 서브트리에서 최대 우수마을 주민 수(부분문제)
// cache[t][1]: t가 우수마을일 때, 마을 t를 루트로 가지는 tree의 서브트리에서 최대 우수마을 주민 수(부분문제)

bool visited[MAX_TOWNS + 1];

ll dfs(int town, int is_good) {
    ll& ret = cache[town][is_good];
    if (ret != -1) return ret;

    visited[town] = true;

    long long mx_good_residents;
    if (is_good) {
        mx_good_residents = residents[town];
        for (int adj: tree[town]){
            if (visited[adj]) continue;
            mx_good_residents += dfs(adj, 0);
        }
    }
    else {
        mx_good_residents = 0;
        for (int adj: tree[town]) {
            if (visited[adj]) continue;
            mx_good_residents += max(dfs(adj, 0), dfs(adj, 1));
        }
    }

    visited[town] = false;
    return ret = mx_good_residents;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> residents[i];
    
    int first, second;
    for (int i = 0; i < n-1; i++) {
        cin >> first >> second;
        tree[first].push_back(second);
        tree[second].push_back(first);
    }

    memset(cache, -1, sizeof(cache));

    cout << max(dfs(1, 0), dfs(1, 1)) << '\n';

    return 0;
}