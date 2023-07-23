#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int N_MAX = 32000;
vector<short> after[N_MAX+1]; // 인접 그래프. after[i]: i번 문제 다음에 풀어야 하는 문제들의 목록
int indegree[N_MAX+1]; // 그래프에서 각 노드의 indegree

set<short> cand; // 지금 풀 문제의 후보들. 이 중 가장 쉬운 문제를 먼저 푼다

int n, m;

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); 
    cin >> n >> m;

    short first, second;
    for (int i=0; i < m; i++) {
        cin >> first >> second;
        after[first].push_back(second);
        indegree[second]++;
    }

    for (int i=1; i <= n; i++) {
        if (indegree[i] == 0) cand.insert(i); // cand를 먼저 풀 문제가 없는 문제들로 초기화
    }

    while (!cand.empty()) {
        auto prob_now = cand.extract(cand.begin()).value(); // cand에서 가장 쉬운 문제를 추출
        cout << prob_now << " ";

        for (auto near : after[prob_now]) { // 인접한 문제 중 지금 풀 문제들을 cand에 추가
            indegree[near]--;
            if (indegree[near] == 0) cand.insert(near);
        }
    }

    return 0;
}