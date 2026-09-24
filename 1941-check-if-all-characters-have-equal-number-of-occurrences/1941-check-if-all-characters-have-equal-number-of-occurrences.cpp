class Solution {
public:
    bool areOccurrencesEqual(string s) {
        map <char,int>m;
        for(auto ch:s){
            m[ch]++;
        }
        int ans;
        if(!m.empty()){
             ans=m.begin()->second;
        }
        for(auto elem:m){
            if(elem.second!=ans){
                return false;
            }
        }
        return true;
    }
};