class Solution {
public:
    int minMoves(vector<int>& nums) {
        ranges::sort(nums);
        int maxi = *ranges::max_element(nums);
        long long ans = 0;
        for(int i: nums){
            ans += abs(i-maxi);
        }
        return ans;
    }
};