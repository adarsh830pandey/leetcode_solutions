class Solution {
public:
int maxNumberOfBalloons(string text) {
map<char, int> m;


    // Count frequency of characters in text
    for (auto elem : text) {
        m[elem]++;
    }

    string ans = "balloon";
    map<char, int> m1;

    // Count frequency of characters in "balloon"
    for (auto elem : ans) {
        m1[elem]++;
    }

    int result = INT_MAX;

    // Find how many times "balloon" can be formed
    for (auto elem : m1) {
        char ch = elem.first;
        result = min(result, m[ch] / elem.second);
    }

    return result;
}
};

