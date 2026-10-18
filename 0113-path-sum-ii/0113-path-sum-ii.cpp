class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        if(!root) return ans;

        queue<pair<pair<TreeNode*, int>, vector<int>>> q;
        q.push({{root, root->val}, {root->val}});

        while(!q.empty()){
            auto [p, path] = q.front();
            q.pop();

            auto [top, sum] = p;

            if(sum == targetSum && !top->left && !top->right){
                ans.push_back(path);
            }

            if(top->left){
                vector<int> temp = path;
                temp.push_back(top->left->val);
                q.push({{top->left, sum + top->left->val}, temp});
            }

            if(top->right){
                vector<int> temp = path;
                temp.push_back(top->right->val);
                q.push({{top->right, sum + top->right->val}, temp});
            }
        }

        return ans;
    }
};