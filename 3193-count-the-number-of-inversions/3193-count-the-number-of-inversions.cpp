class Solution {
public:
    static const int MOD = 1000000007;

    int numberOfPermutations(int n, vector<vector<int>>& requirements) {

        // req[i] = required inversion count
        // for prefix [0 ... i]
        vector<int> req(n, -1);

        for (auto &r : requirements) {
            req[r[0]] = r[1];
        }

        // Maximum possible inversions for n elements
        int maxInv = n * (n - 1) / 2;

        vector<vector<int>> dp(n + 1, vector<int>(maxInv + 1, 0));

        // Empty permutation has 0 inversions
        dp[0][0] = 1;

        for (int len = 1; len <= n; len++) {

            long long window = 0;

            for (int inv = 0; inv <= maxInv; inv++) {

                window += dp[len - 1][inv];

                // We can add at most len-1 new inversions
                if (inv - len >= 0) {
                    window -= dp[len - 1][inv - len];
                }

                window = (window + MOD) % MOD;

                dp[len][inv] = window;
            }

            // If there is a requirement for prefix len-1,
            // keep only that inversion count.
            if (req[len - 1] != -1) {

                int required = req[len - 1];

                for (int inv = 0; inv <= maxInv; inv++) {
                    if (inv != required) {
                        dp[len][inv] = 0;
                    }
                }
            }
        }

        return dp[n][req[n - 1] == -1 ? 0 : req[n - 1]];
    }
};