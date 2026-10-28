class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        k %= nums.size();
        
        reverse(nums.rbegin(),nums.rbegin()+k);
        reverse(nums.rbegin()+k,nums.rend());
        reverse(nums.rbegin(),nums.rend());

    }
};