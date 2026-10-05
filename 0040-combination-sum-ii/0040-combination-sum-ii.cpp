class Solution {
public:
    void solve(int i, int target, vector<int>& temp, vector<int>& arr,
               vector<vector<int>>& ans) {

        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        if (i < 0 || target < 0)
            return;

        // arr[i] is too large, can't take it

        // TAKE
        if (arr[i] <= target) {
            temp.push_back(arr[i]);

            solve(i - 1, target - arr[i], temp, arr, ans);

            temp.pop_back();
        }
        // DON'T TAKE
        // Skip duplicate values
        int j = i - 1;

        while (j >= 0 && arr[j] == arr[i])
            j--;

        solve(j, target, temp, arr, ans);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;
        vector<int> temp;

        solve(candidates.size() - 1, target, temp, candidates, ans);

        return ans;
    }
};