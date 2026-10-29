class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int i = 0, j = 0;
        int n = nums.size();
        int ans = n+1;
        long long sum = 0;
        while(j < n){
            sum += nums[j];
            while(sum >= target){
                ans = min(ans,j-i+1);
                sum -= nums[i];
                i++;
            }
            j++;
        }
        return (ans == n+1)?0:ans ;
    }
};