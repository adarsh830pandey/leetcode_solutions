class Solution {
public:
    void solve(int index, vector<int>& nums,
               vector<int>& current,
               vector<vector<int>>& ans) {

        // Current subset ko answer mein add karo
        ans.push_back(current);

        // Har possible next element ko choose karo
        for (int i = index; i < nums.size(); i++) {

            // Take
            current.push_back(nums[i]);

            // Next elements ke liye recursion
            solve(i + 1, nums, current, ans);

            // Backtrack
            current.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> ans;
        vector<int> current;

        solve(0, nums, current, ans);

        return ans;
    }
};