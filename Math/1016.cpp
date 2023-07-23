/* 
    제곱수의 목록이 있을 때, 
    제곱ㄴㄴ수는 그 목록의 수와 나누어 떨어지지 않는 수를 말한다. 
    이 정의는 소수의 정의와 매우 유사하다고 느껴졌다. 왜냐하면 소수란, 
    그 수보다 작은 수의 목록이 있을 때, 
    그 목록의 수와 나누어 떨어지지 않는 수를 말하기 때문이다. 
    우리는 이 범위의 수 중 소수를 찾아내라는 문제를 빠르게 푸는 에라토스테네스의 체라는
    방법을 알고 있다. 이 문제도 비슷한 방식으로 풀면 어떨까 생각했다. 
    max보다 작은 모든 제곱수의 목록을 두고, 그 목록의 각 수의 배수들을 
    [min, min+1, min+2, ..., max]의 배열에서 지워주는 것이다. 다 끝나고 나면 남은 수들이
    제곱 ㄴㄴ수가 된다. 
    굉장히 나이브한 접근이기 때문에 시간복잡도를 어림잡아봤다. 
    제곱수의 목록은 아무리 길어도 [4, 9, 16, ... , (10^6)^2]으로 O(sqrt(max))이다. 
    목록의 각 수의 배수를 [min, min+1, ..., max]의 배열에서 지움처리하는 작업은 
    O(max - min)이다. 총 시간복잡도는 O((max-min)*sqrt(max))이다. 
    시간복잡도에 문제의 숫자를 넣어 걸릴 시간을 예측하는 (야매) 방식에 따르면, 
    10^6 * 6 <= 10^8이니 1초 이내로 걸릴 것이라 보였다. 

    max보다 작은 모든 제곱수의 목록 대신 max보다 작은 모든 소수 제곱수의 목록을 
    두면 더 빨리 풀릴 것이다. 
 */

#include <iostream>
#include <vector>

using namespace std;

int main(){
    long long int min, max;
    cin >> min >> max;

    // let every number in range be sqaure nono number
    vector<bool> is_sqrnn(max-min+1, true);
    int res = max - min + 1; 

    long long sq;
    for (long long i = 2, sq = i*i; sq <= max; ++i, sq = i*i){
        long long q = min / sq;
        long long r = min % sq;
        long long first = ((r)? (q+1) : q) * sq;

        for (long long j = first; j <= max; j += sq){
            is_sqrnn[j-min] = false;
        }
    }

    int cnt = 0;
    for (int i=0; i < is_sqrnn.size(); i++){
        if (is_sqrnn[i]) {
            cnt++;
        }
    }
    cout << cnt << '\n';
    
    return 0;
}