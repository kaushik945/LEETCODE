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
    int result = -1;
    void inorder(TreeNode* root,int& curr){
        if(!root) return ;
        inorder(root->left,curr);
        curr--;
        if(curr == 0) {
            result = root->val;
        }
        inorder(root->right,curr);
        
        
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        inorder(root,k);
        return result;
    }
};