/*
 * 보석의 무게, 가방의 무게 제한이라는 조건이 없었다고 가정하자. 
 * 그렇다면 보석을 가격내림차순으로 정렬하여 앞에서부터 가방의 개수만큼 가져가는게 답이다. 
 * 다시 무게라는 제한 조건을 추가하자. 그렇다면 비싼 보석부터 담으려고 할 때 어떤 가방에
 * 담아야하는지가 중요해진다. 가장 많은 보석을 담고 싶으니 가장 용량이 작은 가방에 담아야한다. 
 * 즉 가장 비싼 보석부터 담되, 담기는 가방 중 가장 용량이 작은 가방에 담는 전략이다. 
 * (+ 담기는 가방이 없으면 그 보석을 버린다.)
 * 
 * [증명] 귀류법으로 증명
 * 1. 담기는 가방 중 가장 용량이 작은 가방(A)가 아닌 다른 가방(B)에 담는 경우 더 이득이라고 가정하자. 
 *  가장 비싼 보석을 그 가방(B)에 담는다. 이 보석은 담기는 가방 중 가장 용량이 작은 가방(A)로 옮길 수 있다. 
 *  만약 그 가방(A)에 보석이 이미 있다면, 두 보석을 서로 교환할 수도 있다. 따라서 더 이득인 경우는 없다. 
 * 
 * 2. 담기는 가방이 있어도 버리는게 더 이득이라고 가정하자. 
 *  가장 비싼 보석이 담기는 가방이 있었지만 버렸다. 두 상황을 비교한다. 
 *    상황1) 가장 비싼 보석을 담기는 가방 중 가장 용량이 작은 가방에 담는 경우
 *    상황2) 가장 비싼 보석을 버린 경우
 *  상황2인데 남은 보석을 전부 챙길 수 있을 때 가격 합과
 *  상황1인데 남은 보석을 한 개 빼고 전부 챙길 수 있을 때(가장 비싼 보석을 챙기는 바람에 보석 하나를 못 챙김) 가격 합을 비교하면
 *  상황2가 더 이득인 경우는 없다는 것을 알 수 있다. 
*/

#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <set>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

int main(){
    int n, k;
    cin >> n >> k;

    auto comp = [](const auto& j1, const auto& j2) -> bool {
        if (j1.first != j2.first) return j1.first < j2.first;
        return j1.second > j2.second;
    }; // 가격 오름차순, 가격이 같다면 무게 내림차순
    set<pii, vector<pii>, decltype(comp)> jewels(comp); 
    // 각 보석을 {가치, 무게}의 pair로 묶어 우선순위 큐에 저장

    int m, v;
    for (int i=0; i < n; i++) {
        cin >> m >> v;
        jewels.push(make_pair(v, m)); // 순서 바뀜에 주의
    }

    // 가방들은 용량 오름차순 정렬되는 multiset에 저장(같은 용량의 가방이 여러 개 주어지는 경우 때문에 set을 쓸 수 없음)
    multiset<ll> bags;
    for (int i=0; i < k; i++) {
        ll c; cin >> c;
        bags.insert(c);
    }

    ll sum = 0;
    while(!jewels.empty()) { // 남은 보석이 없는 경우 종료
        auto [val, mass] = jewels.top(); // 비싼 보석부터
        jewels.pop(); // 가방에 담는 여부와 상관없이 제거
        auto it = bags.lower_bound(mass); // 담을 수 있는 가장 작은 용량의 가방
        if (it != end(bags)) { // 그런 가방이 존재하면 담는다
            sum += val;
            bags.erase(it);
        }
        if (bags.empty()) break; // 남은 가방이 없는 경우 종료
    }

    cout << sum << '\n';

}