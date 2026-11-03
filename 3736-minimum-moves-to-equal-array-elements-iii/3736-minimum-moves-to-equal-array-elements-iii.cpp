class Solution {
public:
    int minMoves(vector<int>& nums) {
        ranges::sort(nums);
        int maxi = *ranges::max_element(nums);
        int ans = 0;
        for(int i: nums){
            ans += abs(i-maxi);
        }
        return ans;
    }
};