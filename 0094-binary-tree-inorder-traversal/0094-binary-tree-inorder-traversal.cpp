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
    void traverse(vector<int> &ans,TreeNode* root){
        if(root == nullptr) return;
        traverse(ans,root->left);
        ans.push_back(root->val);
        traverse(ans,root->right);
        
    }
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> inorder;
        // TreeNode* temp = root;
        // if(root == nullptr) return inorder;
        // while(true){
        //     if(temp){
        //         st.push(temp);
        //         temp = temp->left;
        //     }else{
        //         if(st.empty()) break;
        //         temp = st.top();
        //         st.pop();
        //         inorder.push_back(temp->val);
        //         temp = temp->right;
        //     }
        // }
        traverse(inorder,root);
        return inorder;
    }
};