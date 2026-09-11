class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        map<int, int> m;

        for (int x : digits) {
            m[x]++;
        }

        int count = 0;

        for (int i = 100; i <= 998; i += 2) {

            int x = i;

            int a = x / 100;        // hundreds
            int b = (x / 10) % 10;  // tens
            int c = x % 10;         // units

            map<int, int> used;
            used[a]++;
            used[b]++;
            used[c]++;

            bool possible = true;

            for (auto elem : used) {
                if (elem.second > m[elem.first]) {
                    possible = false;
                    break;
                }
            }

            if (possible) {
                count++;
            }
        }

        return count;
    }
};