/* 
    N보다 작거나 같은 모든 소수를 찾는다. 
    이런 소수들의 목록(primes)에서 연속된 수의 합(부분합)이 N이 되는 경우의 수를 구한다. 
    이 문제를 해결하기 위해 완전탐색 알고리즘을 먼저 생각할 수 있다. 
    sum(i, j)가 primes의 부분배열 [i, j]의 합을 구하는 함수라면

    int cnt = 0;
    int len = primes.size();
    for (int i=0; i < len; i++){
        for (int j=i; j < len; j++){
            if (sum(i, j) == N) cnt++;
        }
    }
    sum(i, j)의 시간복잡도는 O(1)로 만들 수 있다. 그렇다해도 이 알고리즘은
    O(N^2)의 시간복잡도를 가진다. 

    이 문제를 O(N)에 해결할 수 있는 알고리즘이 있다. 
    int i = 0, j = 0;
    int len = primes.size();
    while (i < len && j < len){
        if (sum(i, j) >= N) {
            if (sum(i, j) == N) cnt++;
            i++;
        }
        else {
            j++;
        }
    }
    
    이 알고리즘은 다음과 같다. 
    - 만약 현재 부분합이 N 이상이면 부분합 범위를 왼쪽에서 하나 줄인다. 
        - 만약 현재 부분합이 N이라면 경우를 하나 발견한 것이다. 
    - 만약 현재 부분합이 N 미만이면 부분합 범위를 오른쪽에 하나 늘린다. 

    이 알고리즘이 유효한 이유는 다음과 같다. 
    현재의 부분배열 [i, j]가 있고 처음 나타날 부분합이 N인 부분배열 [I, J]가 있다고 하자. 
    [I, J]를 못 보고 지나치는 경우는 두 가지가 있을 수 있다. 
    1. i=I가 되기 전 j>J가 되는 경우
        이런 경우는 존재할 수 없다. 
        왜냐하면 i<I인 상태에서 j>J가 되는 경우 부분합이 N을 초과하기 때문이다. 
    2. j=J가 되기 전 i>I가 되는 경우
        이런 경우도 존재할 수 없다. 
        왜냐하면 j<J인 상태에서 i>I가 되는 경우 부분합이 N 미만이기 때문이다. 
 */
#include <iostream>
#include <vector>

using namespace std;

const int MAX = 4'000'000;

vector<bool> is_prime(MAX+1, true);
vector<int> primes;

int main(){
    int n;
    cin >> n;

    // find prime numbers that are <= n
    for (int i=2; i <= n; i++){
        if (is_prime[i]){
            primes.push_back(i);

            for (int j=2*i; j <= n; j += i){
                is_prime[j] = false;
            }
        }
    }

    // int i, j, sum;
    // i = j = sum = 0;

    // int cnt = 0;
    // while (i < primes.size()){
    //     if (sum >= n) {
    //         if (sum == n) cnt++;
    //         sum -= primes[i++];
    //     }
    //     else {
    //         if (j >= primes.size()) break;
    //         sum += primes[j++];
    //     }
    // }

    int i, j, sum;
    i = j = 0;
    sum = (primes.size() > 0)? (primes[0]) : 0;

    int cnt = 0;
    int len = primes.size();
    while (i < len && j < len){
        // sum = arr[i, j] 합
        if (sum >= n) {
            if (sum == n) cnt++;
            sum -= primes[i++];
        }
        else {
            sum += primes[++j];
        }
    }

    cout << cnt << '\n';
}