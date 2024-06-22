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
    void inorder(TreeNode*root,int &sum){
        if(root){
            inorder(root->left,sum);
            sum+=root->val;
            inorder(root->right,sum);
        }
    }
    void PRUNE(TreeNode*&root){
        if(!root){
            return;
        }
        if(root->left){
            int sum1=0;
            inorder(root->left,sum1);
            if(!sum1)root->left=NULL;
        }
        if(root->right){
            int sum2=0;
            inorder(root->right,sum2);
            if(!sum2)root->right=NULL;
        }
        PRUNE(root->left);
        PRUNE(root->right);
    }
    TreeNode* pruneTree(TreeNode* root) {
        if(!root)return NULL;
        int sum=0;
        inorder(root,sum);
        if(!sum)return NULL;
        PRUNE(root);
        return root;
    }
};