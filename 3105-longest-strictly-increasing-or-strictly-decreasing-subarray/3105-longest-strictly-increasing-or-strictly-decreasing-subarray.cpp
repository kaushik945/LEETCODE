class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j= 0;
        int len1 = 1,len2 = 1;
        while(j < n){
            if(j > 0 && nums[j] <= nums[j-1]){
                i = j;
            }
            len1 = max(len1, j-i+1);
            j++;
        }
        i = 0,j=0;
        while(j < n){
            if(j > 0 && nums[j] >= nums[j-1]){
                i = j;
            }
            len2 = max(len2, j-i+1);
            j++;
        }
        return max(len1,len2);
    }
};