class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        vector <int> ans;
        int count=0;
        int n=nums.size();
        for(int i=0; i<n; i++){
            if (nums[i]!=0){
                count=count+1;

            }
            else{
                count=0;
            }
            ans.push_back(count);
            
        }
        int max=INT_MIN;
        for(int i=0; i<ans.size(); i++){
            if(ans[i]>max){
                max=ans[i];
            }
        }
        return max;
    }    
};