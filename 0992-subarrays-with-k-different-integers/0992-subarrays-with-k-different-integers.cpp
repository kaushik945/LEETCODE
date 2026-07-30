class Solution {
public:
    int Subarrays(vector<int>& nums, int k) {
        vector<int> Count(nums.size()+1,0);
        int Distinct = 0,l = 0,Ans = 0;
        for(int r = 0;r<nums.size();r++) {
            if(Count[nums[r]] == 0) Distinct++;
            Count[nums[r]]++;
            while(Distinct > k) {
                Count[nums[l]]--;
                if(Count[nums[l]] == 0) Distinct--;
                l++;
            }
            Ans += r-l+1;
        }
        return Ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return Subarrays(nums,k)-Subarrays(nums,k-1);
    }
};