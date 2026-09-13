class Solution {
public:
    int vowelConsonantScore(string s) {
        int ccount=0;
        int vcount=0;
        for(auto elem:s){
            if(elem=='a'||elem=='i'||elem=='e'||elem=='o'||elem=='u'){
                vcount++;
            }
            else if(isdigit(elem)||isspace(elem)){
                //
            }
            
            else {
                ccount++;
            }
        }
        int score=0;
        if(ccount>0){
            score=floor(vcount/ccount);
            return score;
        }
       return 0;
    }
};