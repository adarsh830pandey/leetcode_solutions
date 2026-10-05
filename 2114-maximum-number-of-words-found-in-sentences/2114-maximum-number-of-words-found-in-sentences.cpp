class Solution {
public:
    int mostWordsFound(vector<string>& s) {
        int n = s.size();
        int maxwords = 0;

        for(int i = 0; i < n; i++) {
            string s1 = s[i];
            int m = s1.size();
            int count = 1;

            for(int j = 0; j < m; j++) {
                if(s1[j] == ' ') {
                    count++;
                }
            }

            maxwords = max(count, maxwords);
        }

        return maxwords;
    }
};