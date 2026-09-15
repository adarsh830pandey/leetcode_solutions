class Solution {
public:
    int sumOfGoodNumbers(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;

        for (int i = 0; i < n; i++) {

            if (i - k < 0) {
                // only right element exists
                if (nums[i] > nums[i + k]) {
                    count += nums[i];
                }
            }
            else if (i + k >= n) {
                // only left element exists
                if (nums[i] > nums[i - k]) {
                    count += nums[i];
                }
            }
            else {
                // both elements exist
                if (nums[i] > nums[i - k] && nums[i] > nums[i + k]) {
                    count += nums[i];
                }
                
            }
        }

        return count;
    }
};