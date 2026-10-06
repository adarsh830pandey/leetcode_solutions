class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int>m;
        for(auto elem:arr){
            m[elem]++;
        }
        vector<int> freq;
        for(auto elem:m){
            freq.push_back(elem.second);
        }
        map<int,int>m2;
        for(auto elem:freq){
            m2[elem]++;
        }
        for(auto elem:m2){
            if(elem.second>1){
                return false;
            }
        }
        return true;
    }
};