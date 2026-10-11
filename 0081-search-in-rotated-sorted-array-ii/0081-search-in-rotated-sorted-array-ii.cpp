class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, h = nums.size() - 1;

        while (l <= h) {
            int mid = (l + h) / 2;

            if (nums[mid] == target)
                return true;
            if(nums[mid] == nums[l] && nums[mid] == nums[h]){
                l++;
                h--;
                continue;
            }
            // Left half is sorted
            if (nums[l] <= nums[mid]) {
                if (nums[l] <= target && target < nums[mid]) {
                    h = mid - 1;
                } else {
                    l = mid + 1;//reject sorted half
                }
            }
            // Right half is sorted
            else {
                if (nums[mid] < target && target <= nums[h]) {
                    l = mid + 1;
                } else {
                    h = mid - 1;//reject
                }
            }
        }

        return false;
    }
};