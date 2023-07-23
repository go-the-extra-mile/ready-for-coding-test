/* 
    가장 작은 수를 만드려면 - 다음에 오는 식을 가장 크게 해야한다. 
    가장 큰 수를 만드려면 - 다음에 오는 식을 가장 작게 해야한다. 
    ex. 5-3+4-7-9-6+5+2-6를 작게 만드려면, 
        3+4-7-9-6+5+2-6를 크게 만드려면, 
        7-9-6+5+2-6를 작게 만드려면, 
        9-6+5+2-6를 크게 만드려면, 
        6+5+2-6를 작게 만드려면, 
        6를 크게 만들어야한다. 
    하지만 이 생각은 틀렸다. 9-6+5+2-6을 가장 작게 만드려면 9-(6+5+2)-6을 하면 된다. 
    실제 예시를 풀어봤다면 이 논리가 틀렸음을 먼저 발견할 수 있었을 것이다. 
 */

#include <iostream>
#include <string>

using namespace std; 

string line;

pair<int, int> advance(int idx){
    int res = 0;
    string cur_num;
    while (idx < line.length() && line[idx] != '-') {
        if ('0' <= line[idx] && line[idx] <= '9'){
            cur_num = cur_num + line[idx];
        }
        else if (line[idx] == '+') {
            int num = stoi(cur_num); 
            res += num;
            cur_num.clear();
        }
        idx++;
    }
    res += stoi(cur_num);
    
    return make_pair(res, ++idx);
}

int max(int stt){
    auto [num, nxt] = advance(stt);
    return ((nxt >= line.length()) ? num : (num - max(nxt)));
}
    
int min(int stt){
    auto [num, nxt] = advance(stt);
    return ((nxt >= line.length())? num : (num - max(nxt))); 
}

int main(){
    cin >> line;
    
    cout << min(0);
}