/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* inorderSuccessor(Node* node) {
        if (!node)return node;
        Node* parent = node->parent;
        if (node->right) {
            Node* root = node->right;
            while (root->left) {
                root = root->left;
            }
            return root;
        }
        if (!parent) {
            Node* root = node->right;
            if (!root)return NULL;
            while (root->left) {
                root = root->left;
            }
            return root;
        }
        if (parent->left == node)return parent;
        while (parent != NULL && parent->right == node) {
            node = parent;
            parent = parent->parent;
        }
        if (parent == NULL)return parent;
        if (parent->left == node)return parent;
        return NULL;
    }
};