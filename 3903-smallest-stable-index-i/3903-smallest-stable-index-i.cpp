class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int maxi = INT_MIN;
            int mini = INT_MAX;

            // max(nums[0...i])
            for (int j = 0; j <= i; j++) {
                maxi = max(maxi, nums[j]);
            }

            // min(nums[i...n-1])
            for (int j = i; j < n; j++) {
                mini = min(mini, nums[j]);
            }

            int score = maxi - mini;

            if (score <= k) {
                return i;
            }
        }

        return -1;
    }
};
 