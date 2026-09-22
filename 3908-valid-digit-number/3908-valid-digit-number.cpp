class Solution {
public:
    bool validDigit(int n, int x) {
        vector<int> digits;

        if (n == 0) {
            digits.push_back(0);
        }

        while (n > 0) {
            int digit = n % 10;
            digits.push_back(digit);
            n = n / 10;
        }

        reverse(digits.begin(), digits.end());

        // First digit should not be x
        if (digits[0] == x) {
            return false;
        }

        // x must occur at least once
        for (int i = 1; i < digits.size(); i++) {
            if (digits[i] == x) {
                return true;
            }
        }

        return false;
    }
};