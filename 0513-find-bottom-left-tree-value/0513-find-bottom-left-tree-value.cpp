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
    int h(TreeNode*r){
        if(!r){
            return 0;
        }
        return max(h(r->left),h(r->right))+1;
    }
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        int he=h(root);
        int c=1;
        TreeNode*ans;
        while(!q.empty()){
            TreeNode*temp=q.front();
            q.pop();
            if(c==he){
                ans=temp;
                break;
            }
            if(temp){
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }else if(!q.empty()){
                q.push(NULL);
                c++;
            }
        }
        return ans->val;
    }
};