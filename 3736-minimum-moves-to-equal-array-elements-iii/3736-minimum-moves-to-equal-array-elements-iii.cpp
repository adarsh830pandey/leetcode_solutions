class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        int max=INT_MIN;
        for(int i=0; i<n; i++){
            if(nums[i]>max){
                max=nums[i];
            }
        }
        sort(nums.begin(),nums.end());
        int count=0;
        for(int i=n-1; i>=0; i--){
            count+=max-nums[i];
        }
        return count;
    }
};