class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0; int j = 0;
        
       while(j<nums.size()){
            int c = 1;
            while((j + 1)< nums.size() && nums[j]==nums[j+1]){
                j++;
                c++;
            }
            c = min(2,c);
            for(int x = 0; x < c; ++x){
                nums[i] = nums[j];
                i++;
            }
            j++;
       }
       return i;
    }
};