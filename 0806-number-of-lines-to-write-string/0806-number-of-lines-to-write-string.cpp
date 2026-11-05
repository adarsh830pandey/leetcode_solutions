class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int n = s.size();
        vector<int> ans;

        int count = 1;
        int m = 0;

        for (int i = 0; i < n; i++) {
            int width = widths[s[i] - 'a'];

            if (m + width > 100) {
                count++;
                m = width;
            }
            else {
                m += width;
            }
        }

        ans.push_back(count);
        ans.push_back(m);

        return ans;
    }
};