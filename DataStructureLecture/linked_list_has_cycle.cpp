#include <iostream>

using namespace std;

class Node {
    public: 
        int data;
        Node * next;
        Node(int data, Node* next) {
            this -> data = data;
            this -> next = next;
        }
};

bool has_cycle(Node* head){
    if (head == NULL) return false;
    
    Node * fast = head->next;
    Node * slow = head;
    while (fast != NULL && fast->next != NULL && slow != NULL){
        if (fast == slow) return true;
        fast = fast->next->next;
        slow = slow->next;
    }
    return false;
}

int main(){
    // 1 - 3 - 4 - 5
    //        \   /
    //          6

    // tc1
    Node * head = new Node(1, NULL);
    Node * three = new Node(3, NULL);
    Node * four = new Node(4, NULL);
    Node * five = new Node(5, NULL);
    Node * six = new Node(6, NULL);
    // Node * seven = new Node(7, NULL);

    head -> next = three;
    three -> next = four;
    four -> next = five;
    five -> next = six;
    six -> next = three;

    cout << has_cycle(head) << '\n';
    return 0;

}