class Solution {
public:
    int atmost(int k,vector<int>& nums){
        if (k < 0) return 0;
        int n = nums.size();
        unordered_map<int,int> freq;
        int i = 0,j = 0;
        int maxlen = 0;
        while(j < n){
            freq[nums[j]]++;
            while(freq.size() > k ){
                freq[nums[i]]--;
                if(freq[nums[i]] == 0) freq.erase(nums[i]);
                i++;
            }
            maxlen += j-i+1;
            j++;
        }
        return maxlen;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmost(k,nums)-atmost(k-1,nums);
    }
};