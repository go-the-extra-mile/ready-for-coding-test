#include <iostream>

using namespace std;

const int mod = 1'000'000;
const int p = 15 * mod / 10; 

int fibo[p] = {0, 1};

int main(){
    long long n;
    cin >> n;
    for (int i=2; i < p; i++){
        fibo[i] = fibo[i-1] + fibo[i-2];
        fibo[i] %= mod;
    }
    cout << fibo[n%p] << '\n';
    return 0;
}