class Solution {
public:
void solve(vector<int>& nums, vector<int>& output,
vector<vector<int>>& ans, vector<bool>& visited) {

    // Base case
    if (output.size() == nums.size()) {
        ans.push_back(output);
        return;
    }

    for (int i = 0; i < nums.size(); i++) {

        // Already used
        if (visited[i]) {
            continue;
        }

        // Skip duplicates
        if (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1]) {
            continue;
        }

        // Include element
        visited[i] = true;
        output.push_back(nums[i]);

        solve(nums, output, ans, visited);

        // Backtracking
        output.pop_back();
        visited[i] = false;
    }
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> output;
    vector<bool> visited(nums.size(), false);

    sort(nums.begin(), nums.end());

    solve(nums, output, ans, visited);

    return ans;
}


};
