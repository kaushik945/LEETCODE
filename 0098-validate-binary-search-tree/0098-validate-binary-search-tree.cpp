class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }
        return isValidBST(root, nullptr, nullptr);
    }

private:
    bool isValidBST(TreeNode* root, const int* min, const int* max) {
        if (root == nullptr) {
            return true;
        }
        if ((min != nullptr && *min >= root->val) ||
            (max != nullptr && *max <= root->val)) {
            return false;
        }
        bool left = isValidBST(root->left, min, &root->val);
        bool right = isValidBST(root->right, &root->val, max);
        return left && right;
    }
};