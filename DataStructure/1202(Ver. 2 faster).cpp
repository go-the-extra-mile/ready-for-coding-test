/**
 * 가장 용량이 작은 가방부터, 담을 수 있는 가장 비싼 보석을 담는다
 * 이를 위해 가방을 용량 오름차순으로 정렬, 보석을 무게 오름차순으로 정렬한다
 * 가장 용량이 작은 가방부터, 담기는 보석을 가격 높은 것이 위로 오는 heap에 담는다
 * max heap, red-black tree ascending/descending으로 각각 시험한 결과 max heap이 가장 공간 효율적, 시간 효율적이였다
 * red-black tree ascending/descending간에는 차이가 전혀 없었다
 * 
 * Ver. 1은 가장 비싼 보석부터, 가장 꽉 맞는(담기는 가장 용량 작은) 가방에 담는 전략을 썼다. 
 * 이 전략은 가장 꽉 맞는 가방을 찾기 위해 가방을 정렬해둔 뒤, lower_bound같은 방식으로 선형 탐색해야 하기에
 * 태생적으로 덜 효율적이다. 
*/
#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

pii jewels[300'000]; // {무게, 가격}의 목록
int bags[300'000]; // 가방 용량의 목록
set<int> prices; // 보석 가격의 max heap

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    for (int i=0; i < n; i++) {
        cin >> jewels[i].first >> jewels[i].second;
    }
    for (int i=0; i < k; i++) {
        cin >> bags[i];
    }

    sort(jewels, jewels+n);
    sort(bags, bags+k);

    ll sum = 0;
    int resume_idx = 0;
    for (int i=0; i < k; i++) {
        while (resume_idx < n && jewels[resume_idx].first <= bags[i]) {
            prices.push(jewels[resume_idx].second);
            resume_idx++;
        }

        if (prices.empty()) continue;
        sum += prices.top();
        prices.pop();
    }

    cout << sum << '\n';

    return 0;
}