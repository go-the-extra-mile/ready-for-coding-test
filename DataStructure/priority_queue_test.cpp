#include <iostream>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

struct compare {
    bool operator() (int& lhs, int& rhs) {
        return lhs > rhs;
    }
};

int main() {
    set<int, vector<int>, compare> pq; // makes it a min heap

    auto comp2 = [](auto& lhs, auto& rhs) -> bool {
        return lhs > rhs;
    };
    set<int, vector<int>, decltype(comp2)> pq2 {comp2};

    pq.push(1);
    pq.push(2);
    pq.push(3);
    pq.push(4);
    cout << pq.top() << '\n';

    pq2.push(1);
    pq2.push(2);
    pq2.push(3);
    pq2.push(4);
    cout << pq2.top() << '\n';

    return 0;
    
}