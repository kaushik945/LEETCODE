
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size(), l = 0, r = n-1;
        int ans = nums[0];

        while(l <= r){
            int m = (l+r)/2;

            if(nums[m] == nums[l] && nums[m] == nums[r]){
                ans = min(ans, nums[m]);
                l++;
                r--;
                continue;
            }

            if(nums[l] <= nums[m]){
                ans = min(ans, nums[l]);
                l = m+1;
            }
            else{
                ans = min(ans, nums[m]);
                r = m-1;
            }
        }

        return ans;
    }
};
