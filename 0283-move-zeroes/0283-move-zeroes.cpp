class Solution {
public:
    void moveZeroes(vector<int>& arr) {
        int j=0;
        int end=arr.size();
        for(int i=0; i<end; i++){
            if(arr[i]!=0){
                swap(arr[i],arr[j]);
                j++;
            }
            
        }
       

        
    }
};