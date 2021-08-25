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
        if (!node) return node;
//         means node is root
        if (node->parent == NULL || node->parent->val > node->val) {
            Node* ret = inorder(node->right);
            if (!ret)return node->parent;
            return ret;
        } else {
            Node* ret = inorder(node->right);
            int target = node->val;
            if (ret) return ret;
            while (node->parent) {
                node = node->parent;
                if (node->val > target) {
                    return node;
                }
            }
            return ret;
        }
        return NULL;
    }
    
    Node* inorder(Node* root) {
        if (!root) return root;
        vector<Node*>todo;
        while (root) {
            if (!root->left)return root;
            root = root->left;
        }
        return NULL;
    }
};
