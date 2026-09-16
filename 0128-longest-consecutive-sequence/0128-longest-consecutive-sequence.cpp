class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }

        sort(nums.begin(), nums.end());

        set<int> s(nums.begin(), nums.end());

        vector<int> arr(s.begin(), s.end());

        int count = 1;
        int maxi = 1;

        for (int i = 1; i < arr.size(); i++) {

            if (arr[i] - arr[i - 1] == 1) {
                count++;
            }
            else {
                count = 1;
            }

            maxi = max(maxi, count);
        }

        return maxi;
    }
};
        
