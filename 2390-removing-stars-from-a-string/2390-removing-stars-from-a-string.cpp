class Solution {
public:
    string removeStars(string s) {
        int n=s.size();
        string ans="";
        stack<char>st;
        st.push(s[0]);
        for(int i=1; i<n; i++){
            if(s[i]=='*'){
                st.pop();
            }
            else{
                st.push(s[i]);
            }  
            
            
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;


    }
};