class Node {
    public: 
        Node* left;
        Node* right;
        int data;

        Node* right_rotate(Node* node){
            Node* tmp = node->left;
            node->left = tmp->right;
            tmp->right = node;
            return tmp;
        }

        Node* left_rotate(Node* node){
            Node* tmp = node->right;
            node->right = tmp->left;
            tmp->left = node;
            return tmp;
        }

        Node* right_left_rotate(Node* node){
            node->right = right_rotate(node->right);
            return left_rotate(node);
        }

        Node* left_right_rotate(Node* node){
            node->left = left_rotate(node->left);
            return right_rotate(node);
        }

}