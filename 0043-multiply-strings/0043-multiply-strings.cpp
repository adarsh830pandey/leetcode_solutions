class Solution {
public:
    string multiply(string num1, string num2) {

        int n = num1.size();
        int m = num2.size();

        vector<int> ans(n + m, 0);

        for(int i = n-1; i >= 0; i--) {

            for(int j = m-1; j >= 0; j--) {

                int prod = (num1[i]-'0') * (num2[j]-'0');

                int sum = prod + ans[i+j+1];

                ans[i+j+1] = sum % 10;

                ans[i+j] += sum / 10;
            }
        }

        string result = "";

        for(int digit : ans) {
            if(!(result.empty() && digit == 0)) {
                result += to_string(digit);
            }
        }

        return result.empty() ? "0" : result;
    }
};