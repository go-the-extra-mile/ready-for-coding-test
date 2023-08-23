/*
가장 기본적인 위상정렬 문제이다. 
위상정렬이란 비순환 유향 그래프의 vertex들을 edge의 방향을 거스르지 않도록 나열하는 것이다. 
선후수 조건이 있는 과목을 이수 가능한 순서대로 나열하는 것이 대표적인 활용 예시다. 

위상정렬 알고리즘
1. 자신을 가리키는 edge가 없는 vertex를 찾는다. 
2. 찾은 vertex를 출력하고 그 vertex와 vertex가 출발점인 edge를 지운다. 
3. 아직 그래프에 vertex가 남아있다면 1단계로 돌아간다. 

자신을 가리키는 edge 수를 담는 indegree 배열과 자신을 가리키는 edge가 없는 vertex를 담는 queue를 이용해
위상정렬을 구현했다. 
*/
#include <iostream>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

const int N_MAX = 32000;
const int M_MAX = 100000;

int indegree[N_MAX + 1]; // indegree[i]: vertex i를 가리키는 edge 수
vector<int> graph[N_MAX + 1]; 

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    int left, right;
    for (int i = 0; i < m; i++) {
        cin >> left >> right;
        graph[left].push_back(right);
        (indegree[right])++;
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) q.push(i); // queue에 자신을 가리키는 edge가 없는 vertex를 넣고 시작
    }

    while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        cout << cur << " ";
        for (auto next: graph[cur]) { // cur이 출발점인 edge를 삭제(= next의 indegree를 감소) 시키며...
            (indegree[next])--;
            if (indegree[next] == 0) { // ...자신을 가리키는 edge가 모두 사라진 vertex를 queue에 삽입
                q.push(next);
            }
        }
    }

    return 0;
}