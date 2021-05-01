/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int longestConsecutive(TreeNode* root) {
        if (!root)return 0;
        int prev = root->val;
        int ret = 1;
        vector<TreeNode*>seq;
        //seq.push_back(root);
        longestSub(root->left, prev, 1, ret);
        longestSub(root->right, prev, 1, ret);
        if (root->left)ret = max(ret, longestConsecutive(root->left));
        if (root->right)ret = max(ret, longestConsecutive(root->right));
        return ret;
    }
    
    void longestSub(TreeNode* root, int prev, int cur, int& ret){
        if (!root)return ;
        if (root->val == prev + 1){
            ret = max(cur+1, ret);
            longestSub(root->left, root->val, cur+1, ret);
            longestSub(root->right, root->val, cur+1, ret);
        }
        ret = max(ret, longestConsecutive(root->left));
        ret = max(ret, longestConsecutive(root->right));
    }
};
