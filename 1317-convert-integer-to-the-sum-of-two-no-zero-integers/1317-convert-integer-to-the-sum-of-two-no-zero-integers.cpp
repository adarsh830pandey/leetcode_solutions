class Solution {
public:
  

    vector<int> getNoZeroIntegers(int n) {
        for (int i = 1; i < n; i++) {
            int a = i;
            int b = n - i;

            if (check(a) && check(b)) {
                return {a, b};
            }
        }

        return {};
    }


  bool check(int x) {
        while (x > 0) {
            if (x % 10 == 0)
                return false;

            x = x / 10;
        }

        return true;
    }
};


