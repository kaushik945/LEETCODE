class Solution {
public:
    void solve(int i, int target,
               vector<int> temp,
               vector<int>& arr,
               vector<vector<int>>& ans) {

        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        if (target < 0 || i < 0)
            return;

        if (i == 0) {
            if (target % arr[0] == 0) {
                for (int j = 0; j < target / arr[0]; j++) {
                    temp.push_back(arr[0]);
                }

                ans.push_back(temp);
            }
            return;
        }

        // Take arr[i]
        if (arr[i] <= target) {
            temp.push_back(arr[i]);

            solve(i, target - arr[i], temp, arr, ans);

            temp.pop_back();
        }

        // Don't take arr[i]
        solve(i - 1, target, temp, arr, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;

        solve(candidates.size() - 1,
              target,
              {},
              candidates,
              ans);

        return ans;
    }
};