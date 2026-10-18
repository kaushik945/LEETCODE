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
    void pathSumUtil(TreeNode* root, vector<vector<int>> &res, vector<int> &v, int targetSum){
        
        if(!root) return;
        v.push_back(root->val);
        if(!root->left and !root->right){
            if(root->val == targetSum){
                
                res.push_back(v);
                
            }
            
        }
        
        pathSumUtil(root->left, res, v, targetSum - root->val);
        pathSumUtil(root->right, res, v, targetSum - root->val);
        v.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> v;
        pathSumUtil(root, res, v, targetSum);
        return res;
    }
};