/*
    자료구조에서 많이 해멘 문제. 풀이 설계 중에 자료구조까지 완전히 생각하고 코드를 쳐야겠다. 
*/
#include <iostream>
#include <map>
#include <utility>
#include <string>

using namespace std;

// Node는 방 하나에 해당한다. 
// Node는 하위 방에 있는 먹이의 이름과 하위 방 포인터를 먹이 이름 순으로 정렬한 채로 가지고 있다. 
struct Node {
    map<string, Node*> children;
};

// node가 가리키는 방의 하위방 먹이를 이름 순으로 출력한다
// 각 하위방을 재귀적으로 호출한다
void dfs(Node * node, int level) {
    auto& children = node->children;
    if (children.empty()) return;

    for (auto it = begin(children); it != end(children); it++) { 
        // it: 노드가 가리키는 각 하위 방
        for (int i = 0; i < level; i++) {
            cout << "--";
        }
        auto& food = it->first; // it->first: 하위 방의 음식
        auto& child = it->second; // it->second: 하위 방을 가리키는 포인터

        cout << food << '\n';
        
        dfs(child, level+1);
    }
}

int main() {
    int n;
    cin >> n;

    Node* head = new Node();
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;

        Node* parent = head; // parent를 입구에 해당하는 방 포인터로 초기화한다
        while(k--) {
            string food; cin >> food;
            
            auto& children = parent->children; // children은 parent의 하위 방들이다. 
            if (!children.count(food)) 
                children[food] = new Node(); // food 하위 방이 없으면 만들어준다. 

            parent = children[food]; // parent를 하위 방 포인터로 업데이트한다
        }
    }

    dfs(head, 0);

    return 0;
    
}