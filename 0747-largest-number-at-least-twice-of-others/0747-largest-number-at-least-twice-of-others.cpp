class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int max=INT_MIN;
        int index=0;
        for(int i=0;i<nums.size(); i++){
            if(nums[i]>max){
                max=nums[i];
                index=i;
            }
        }
        for(int i=0; i<nums.size(); i++){
            //wrong case lagaunga
            //agar ek bhi chhota hua to khel khatam
            if(max<nums[i]*2 && max!=nums[i]){
                return -1;
            }
        }
        return index;
        
    }
};