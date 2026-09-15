class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int n = nums.size();

        // Store all indexes for each value
        unordered_map<int, vector<int>> m;

        for (int i = 0; i < n; i++) {
            m[nums[i]].push_back(i);
        }

        int count = 0;

        for (auto elem : m) {

            vector<int> v = elem.second;

            // At least 3 occurrences
            if (v.size() < 3) {
                continue;
            }

            bool special = true;

            int diff = v[1] - v[0];

            // Check all consecutive differences
            for (int i = 2; i < v.size(); i++) {
                if (v[i] - v[i - 1] != diff) {
                    special = false;
                    break;
                }
            }

            // Check after the complete loop
            if (special) {
                count++;
            }
        }

        return count;
    }
};
