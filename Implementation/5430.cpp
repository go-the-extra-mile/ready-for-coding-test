#include <iostream>
#include <string>
#include <deque>
#include <cstdlib>
#include <iterator>

using namespace std;

string line;
string p;
deque<int> nums;

void print_deque(){
    
    auto it = nums.begin();
    auto end = nums.end();
    

    cout << '[';
    for (; it != end; it++){
        cout << *it;
        if (next(it) != end) cout << ",";
    }
    cout << "]\n";
    
    
}

void print_deque_reverse(){
    auto it = nums.rbegin();
    auto end = nums.rend();
    
    cout << '[';
    for (; it != end; it++){
        cout << *it;
        if (next(it) != end) cout << ",";
    }
    cout << "]\n";
}

int main(){
    
    getline(cin, line);
    int t = stoi(line);
    
    int n;
    while(t--){
        getline(cin, p);
        getline(cin, line);
        n = stoi(line);
        
        // {
        //     cout << "got command line: " << p << '\n';
        //     cout << "got n: " << n << '\n';
        // }
        
        nums.clear();
        getline(cin, line);
        const char * str = line.c_str();
        
        // {
            
        //     cout << "got nums: " << str << '\n';
        // }
        
        if (n != 0){
            char * idx = (char *)str + 1;
            while (*idx != '\0'){
                int num = strtol(idx, &idx, 10);
                nums.push_back(num);
                
                idx++;
            }
        }
        
        
        bool is_reverse = false;
        bool is_error = false;
        
        for (const auto& ch: p){
            if (ch == 'R'){
                is_reverse = !is_reverse;
            }
            else if (ch == 'D') {
                if (nums.size() == 0) {
                    is_error = true;
                    break;
                }
                if (is_reverse) nums.pop_back();
                else nums.pop_front();
            }
        }
        

        
        if (is_error) {
            cout << "error\n";
            continue;
        }
        
        if (is_reverse) print_deque_reverse();
        else print_deque();
        

    }
}