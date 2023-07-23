#include <iostream>
#include <utility>

using namespace std;

pair<int, int> f(int a, int b){
    return make_pair(a, b);
}

int main(){
    auto [first, second] = f(3, 6);
    cout << first << ' ' << second << '\n';

    pair<int, int> p{4, 5};
    auto [i, s] = p;
    cout << i << ' ' << s << '\n';
    
    return 0;
}