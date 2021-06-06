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
        map<TreeNode*, int>dict;
        int ret = 1;
        int lv = longsub(root->left, dict, root->val);
        int rv = longsub(root->right, dict, root->val);
        dict[root] = max(lv + 1, rv + 1);

        for (auto kv : dict) {
            if (kv.second > ret)ret = kv.second;
        }
        return ret;
    }

    int longsub(TreeNode* root, map<TreeNode*, int>& dict, int prev) {
        if (!root)return 0;

        if (dict[root] > 0)return dict[root];
        int lv = longsub(root->left, dict, root->val);
        int rv = longsub(root->right, dict, root->val);
        dict[root] = max(lv + 1, rv + 1);
        if (root->val != prev + 1)return 0;
        return max(lv + 1, rv + 1);
    }
};