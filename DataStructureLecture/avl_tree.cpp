#include <iostream>
#include <cmath>

class Node{
    public: 
        int data;
        Node* left;
        Node* right;
        Node* parent;
        Node(int data){
            left = right = parent = NULL;
            this->data = data;
        }
};

class AVLTree{
    public: 
        Node* root;
        int currentSize;

        AVLTree(){
            root = NULL;
            currentSize = 0;
        }

        void add(int data){
            Node* node = new Node(data);
            if(root == NULL) {
                root = node;
                currentSize++;
                return;
            }
            add(root, node);
        }

        void add(Node* parent, Node* new_node){
            if(new_node->data > parent->data){
                // add to right
                if(parent->right == NULL){
                    parent->right = new_node;
                    new_node->parent = parent;
                    currentSize++;
                }
                else{
                    add(parent->right, new_node);
                }
            }
            else{
                // add to left
                if(parent->left == NULL){
                    parent->left = new_node;
                    new_node->parent = parent;
                    currentSize++;
                }
                else{
                    add(parent->left, new_node);
                }
            }
            check_balance(new_node);
        }

        void check_balance(Node *node) {
            // if imbalance: height difference between left and right subtrees is bigger than 1
            if (std::abs(height(node->left) - height(node->right)) > 1)
                rebalance(node);
        
            if (node->parent == NULL)
                return; // node at root
            check_balance(node->parent);
        }

        void rebalance(Node *node){
            // figure out type of violation
            // if left subtree > right subtree
            if (height(node->left) - height(node->right) > 1){
                // if imbalance at left child's left subtree
                // = if left left subtree > left right subtree
                if (height(node->left->left) > height(node->left->right))
                {
                    node = right_rotate(node);
                }
                // if imbalance at left child's right subtree
                else
                {
                    node = left_right_rotate(node);
                }
            }
            // if left subtree <= right subtree
            else{
                // if imbalance at right child's left subtree
                // = if right left subtree > right right subtree
                if (height(node->right->left) > height(node->right->right))
                {
                    node = right_left_rotate(node);
                }
                // if imbalance at right child's right subtree
                else
                {
                    node = left_rotate(node);
                }
            }
            if (node->parent == NULL)
                root = node;
        }
};