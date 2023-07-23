#include <iostream>
#include <cstring>

using namespace std;

int main(){
    int t;
    cin >> t;
    
    bool is_prime[10001];
    memset(is_prime, 1, sizeof(is_prime));
    for (int i=2; i <= 10000; i++){
        if (is_prime[i]){
            for (int j=i*2; j <= 10000; j += i){
                is_prime[j] = false;
            }
        }
    }

    int n;
    while(t--){
        cin >> n;
        for (int big = n/2; big <= n; big++){
            int small = n - big;
            if (is_prime[big] && is_prime[small]) {
                cout << small << ' ' << big << '\n';
                break;
            }
        }
    }

    return 0;
}