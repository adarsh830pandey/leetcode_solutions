class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        
        map<char, string> m = {
            {'a', ".-"}, {'b', "-..."}, {'c', "-.-."}, {'d', "-.."},
            {'e', "."}, {'f', "..-."}, {'g', "--."}, {'h', "...."},
            {'i', ".."}, {'j', ".---"}, {'k', "-.-"}, {'l', ".-.."},
            {'m', "--"}, {'n', "-."}, {'o', "---"}, {'p', ".--."},
            {'q', "--.-"}, {'r', ".-."}, {'s', "..."}, {'t', "-"},
            {'u', "..-"}, {'v', "...-"}, {'w', ".--"}, {'x', "-..-"},
            {'y', "-.--"}, {'z', "--.."}
        };

        set<string> st;

        for(int i = 0; i < words.size(); i++) {
            string temp = "";

            for(int j = 0; j < words[i].size(); j++) {
                temp += m[words[i][j]];
            }

            st.insert(temp);
        }

        return st.size();
    }
};