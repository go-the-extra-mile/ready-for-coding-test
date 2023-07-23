#include <iostream>

using namespace std;

class Node{
    public: 
        Node* left;
        Node* right;
        int data;

        Node(int data){
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }

        void insert(int value){
            if (value <= data){
                if (left == NULL){
                    left = new Node(value);
                }
                else {
                    left->insert(value);
                }
            }
            else {
                if (right == NULL){
                    right = new Node(value);
                }
                else {
                    right->insert(value);
                }
            }
        }

        bool contains(int value){
            if (value == data) {
                return true;
            }
            else if (value < data) {
                if (left == NULL){
                    return false;
                }
                else {
                    return left->contains(value);
                }
            } 
            else {
                if (right == NULL){
                    return false;
                }
                else {
                    return right->contains(value);
                }
            }
        }

        void inorder_traverse(){
            // left
            if (left != NULL) {
                left->inorder_traverse();
            }
            // root
            cout << data << ' ';
            // right
            if (right != NULL) {
                right->inorder_traverse();
            }
        }
};

int main(){
    Node * root = new Node(10);
    cout << "create " << root->data << '\n';
    root->insert(5);
    cout << "insert" << '\n';
    root->insert(15);
    cout << "insert" << '\n';
    root->insert(8);
    cout << "insert" << '\n';

    cout << "root->contains(5)" << root->contains(5) << '\n';
    cout << "root->contains(8)" << root->contains(8) << '\n';
    cout << "root->contains(10)" << root->contains(10) << '\n';
    
    root->inorder_traverse();
    return 0;
}

