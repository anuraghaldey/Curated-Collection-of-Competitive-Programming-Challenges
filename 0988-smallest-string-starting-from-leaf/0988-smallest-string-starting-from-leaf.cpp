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
    void dfs(TreeNode* root, string& p, string& s) {
        if (!root) {
            return;
        }
        p.insert(0, 1, 'a' + root->val); 
        if (!root->left && !root->right) {
            if (s.empty() || p < s) {
                s = p; 
            }
        }
        dfs(root->left, p, s);
        dfs(root->right, p, s);
        p.erase(0, 1); 
    }

    string smallestFromLeaf(TreeNode* root) {
        string s;
        string p; 
        dfs(root, p, s);
        return s;
    }
};