class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        st.push(0);

        for(int i = 0; i < s.size(); i++) {

            if(s[i] == '(') {
                st.push(0);
            }
            else {
                int x = st.top();
                st.pop();

                int score;

                if(x == 0) {
                    score = 1;       // ()
                }
                else {
                    score = 2 * x;   // (A)
                }

                st.top() += score;  // AB ke liye add
            }
        }

        return st.top();
    }
};