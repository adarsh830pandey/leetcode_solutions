class Solution {
public:
    string makeGood(string s) {
        stack<char> st;

        for (char elem : s) {

            if (!st.empty() &&
                tolower(st.top()) == tolower(elem) &&
                islower(st.top()) != islower(elem)) {
                
                st.pop();
            }
            else {
                st.push(elem);
            }
        }

        string ans = "";

        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};