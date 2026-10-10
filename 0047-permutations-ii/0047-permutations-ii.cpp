class Solution {
public:
    void func(vector<int>& nums,
              vector<int>& temp,
              vector<int>& used,
              vector<vector<int>>& ans) {

        if (temp.size() == nums.size()) {
            ans.push_back(temp);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {

            if(i > 0 && nums[i] == nums[i-1] && !used[i-1]) continue;
            if (used[i])
                continue;

            used[i] = 1;
            temp.push_back(nums[i]);

            func(nums, temp, used, ans);

            temp.pop_back();
            used[i] = 0;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        vector<int> used(nums.size(), 0);
        ranges::sort(nums);
        func(nums, temp, used, ans);

        return ans;
    }
};