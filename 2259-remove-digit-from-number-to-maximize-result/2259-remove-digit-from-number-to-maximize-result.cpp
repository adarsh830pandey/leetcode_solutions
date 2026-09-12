class Solution {
public:
    string removeDigit(string number, char digit) {
        int n=number.size();
        string ans="";
        for(int i=0; i<n; i++){
            string temp=number;
            if(number[i]==digit){
                temp.erase(i,1);
                ans=max(temp,ans);
            }
        }
        return ans;
    }
};