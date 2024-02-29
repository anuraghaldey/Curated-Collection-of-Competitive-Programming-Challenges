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
    
    
    bool isEvenOddTree(TreeNode* root) {
    if (!root) return true; 
    
    queue<TreeNode*> q;
    q.push(root);
    q.push(NULL); 
    int lev = 0;
    int prev = -1; 
    while (!q.empty()) {
        TreeNode* temp = q.front();
        q.pop();
        
        if (temp) { 
            int num = temp->val;
            if ((lev % 2 && (num % 2 || num >= prev)) || (!(lev % 2) && (!(num % 2) || num <= prev))) { 
                return false;
            }
            prev = num;
            if (temp->left) {
                q.push(temp->left);
            }
            if (temp->right) {
                q.push(temp->right);
            }
        } else if (!q.empty()) {
            q.push(nullptr);
            lev++;
            if(lev%2){
                prev=1e6+2;
            }else{
                prev = -1;
            }
        }
    }
    return true;
}

};