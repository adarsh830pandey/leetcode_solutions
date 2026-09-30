class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        int n=num.size();
        for(int i=0; i<n; i++){
            char ch=num[i];
            while(!st.empty() && st.top()>ch && k>0){
                st.pop();
                k--;
            }
            st.push(ch);
            
        }
        while(k>0 && !st.empty()){
                st.pop();
                k--;
            }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        //o vala case handle karrneka hai
        int i=0;
        while(ans[i]=='0'){
            ans.erase(ans.begin()+i);
        }
        return ans.empty()?"0":ans;
    }
};