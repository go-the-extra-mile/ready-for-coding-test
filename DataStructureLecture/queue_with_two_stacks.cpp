#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class Queue{
    private:
        stack<int> stack_newest;
        stack<int> stack_oldest;

        void shift_elements() {
            // move elements from stack_newest to stack_oldest when stack_oldest is empty   
            if (stack_oldest.empty()){
                while (!stack_newest.empty()) {
                    int top = stack_newest.top();
                    stack_newest.pop();
                    stack_oldest.push(top);
                }
            }
        }

    public:
        Queue() {
            this -> stack_newest = stack<int>();
            this -> stack_oldest = stack<int>();
        }

        void enqueue(int value) { // add value
            stack_newest.push(value);
        }

        int peek() { // get "oldest" item
            // q: 2 3 4 5
            // newest: 4 5
            // oldest: 3 2

            shift_elements();
            // peek top of oldest
            return stack_oldest.top();
        }

        int dequeue() { // get "oldest" item and delete
            int oldest = peek();
            stack_oldest.pop();
            return oldest;
        }
};

int main(){
    Queue q = Queue();
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    // 1 2 3
    cout << "peek: " << q.peek() << '\n'; // 1
    cout << "dequeue: " << q.dequeue() << '\n'; // 1
    
    // 2 3 4 5
    q.enqueue(4); 
    q.enqueue(5);

    cout << "peek: " << q.peek() << '\n'; // 2
    cout << "dequeue: " << q.dequeue() << '\n';
    cout << "peek: " << q.peek() << '\n'; // 3
    cout << "dequeue: " << q.dequeue() << '\n';
    cout << "peek: " << q.peek() << '\n'; // 4
    cout << "dequeue: " << q.dequeue() << '\n';
    cout << "peek: " << q.peek() << '\n'; // 5
    cout << "dequeue: " << q.dequeue() << '\n';

    return 0;
    
}