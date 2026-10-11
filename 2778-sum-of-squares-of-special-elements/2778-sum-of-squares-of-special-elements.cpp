class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int sum = 0;
        int i = 1,n = nums.size();
        for(auto &it: nums){
            if(n%(i++) == 0) sum += it*it;
        }
        return sum;
    }
};