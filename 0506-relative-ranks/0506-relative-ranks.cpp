class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& arr) {
        int n = arr.size();
        vector<string> ans;
        
        vector<int> temp = arr;
        sort(temp.begin(), temp.end(), greater<int>());
        map<int, string> m;
        for(int i = 0; i < n; i++) {
            if(i == 0) {
                m[temp[i]] = "Gold Medal";
            }
            else if(i == 1) {
                m[temp[i]] = "Silver Medal";
            }
            else if(i == 2) {
                m[temp[i]] = "Bronze Medal";
            }
            else {
                m[temp[i]] = to_string(i + 1);
            }
        }
         for(int i = 0; i < n; i++) {
            ans.push_back(m[arr[i]]);
        }

        return ans;
    }
};