class Solution {
public:
    void generate(int open,int close,int n,string s, vector<string>&ans){
        //base case
        if(s.size()==2*n){
            ans.push_back(s);
            return;
        }
        //open bracket case
        if(open<n){
            generate(open+1,close,n,s+'(',ans);
        }
        //close bracket case
         if(close<open){
            generate(open,close+1,n,s+')',ans);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        generate(0,0,n,"",ans);
        return ans;
        
    }
};