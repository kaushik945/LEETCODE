class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorr = 0;
        for(int i : nums) xorr ^= i;
        long long rmb = ((xorr*1LL-1)&xorr) ^ xorr;
        int ele1 = 0, ele2 = 0;
        for(int i: nums){
            if(rmb & i){
                ele1 ^= i;
            }else{
                ele2 ^= i;
            }
        }
        return {ele1,ele2};
    }
};