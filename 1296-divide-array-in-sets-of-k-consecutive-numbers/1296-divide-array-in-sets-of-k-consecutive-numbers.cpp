class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
            // Total number of elements must be divisible by k
    if (nums.size() % k != 0)
        return false;

    // Sort the array so we always start from the smallest
    // available element
    sort(nums.begin(), nums.end());

    // Store the frequency of every number
    unordered_map<int, int> freq;

    for (auto it : nums) {
        freq[it]++;
    }

    // Traverse the sorted array
    for (int i = 0; i < nums.size(); i++) {

        // If this number has already been used,
        // skip it
        if (freq[nums[i]] == 0)
            continue;

        else if (freq[nums[i]] > 0) {

            // Use one occurrence of the starting number
            freq[nums[i]]--;

            // We need k-1 more consecutive numbers
            int j = 1;

            while (j != k) {

                // The next required number is
                // nums[i] + j
                if (freq[nums[i] + j] > 0) {

                    // Use one occurrence of this number
                    freq[nums[i] + j]--;

                    j++;
                }

                // Required consecutive number is not available
                else
                    return false;
            }
        }
    }

    // All elements were successfully divided
    // into groups of size k
    return true;
    }
};