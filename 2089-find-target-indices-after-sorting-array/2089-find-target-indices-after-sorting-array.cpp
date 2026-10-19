class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> freq(101);
        for(auto it:nums){
            freq[it]++;
        }
        int sz = 0;
        for(int i = 0; i < target; i++){
            sz += freq[i];
        }
        vector<int> ans;
        for(int i = sz; i < freq[target] + sz; i++){
            ans.push_back(i);
        }
        return ans;
    }
};