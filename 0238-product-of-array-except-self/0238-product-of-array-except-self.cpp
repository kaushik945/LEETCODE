class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int curr = 1, n = nums.size();
        vector<int> ans(n,1);
        for(int i = 1; i < n; i++){
            ans[i] = nums[i-1]*ans[i-1];  
        }
        for(int i = n-2; i >= 0; i--){
            ans[i] *= nums[i+1]*curr;  
            curr *= nums[i+1];
        }
        return ans;
    }
};