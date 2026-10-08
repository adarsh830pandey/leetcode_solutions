class Solution {
public:
    bool rotateString(string s, string goal) {
       string temp=s+s;
       if(s.size()!=goal.size()){
        return false;
       }
       if(temp.find(goal)!=string::npos) {
        return true;
       }
       else{
        return false;
       }
    }
};