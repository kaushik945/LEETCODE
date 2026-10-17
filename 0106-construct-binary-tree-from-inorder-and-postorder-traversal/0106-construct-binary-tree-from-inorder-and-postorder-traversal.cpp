/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> hash;
        for (int i = 0; i < inorder.size(); i++) {
            hash[inorder[i]] = i;
        }

        TreeNode* root = buildTree(postorder, 0, postorder.size() - 1, inorder,
                                   0, inorder.size() - 1, hash);
        return root;
    }
    TreeNode* buildTree(vector<int>& postorder, int postStart, int postEnd,
                        vector<int>& inorder, int inStart, int inEnd,
                        unordered_map<int, int>& hash) {
        if (postStart > postEnd || inStart > inEnd)
            return NULL;
        TreeNode* root = new TreeNode(postorder[postEnd]);
        int curr = hash[postorder[postEnd]];
        int after = inEnd - curr;

        root->left = buildTree(postorder, postStart, postEnd - after - 1,
                               inorder, inStart, curr - 1, hash);

        root->right = buildTree(postorder, postEnd - after, postEnd - 1,
                                inorder, curr + 1, inEnd, hash);
        return root;
    }
};