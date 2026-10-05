class Solution {
public:
    bool canPlaceFlowers(vector<int>&arr, int n) {
        int size=arr.size();
        for(int i=0; i<size; i++){
            if(arr[i]==0 && (i==0||arr[i-1]==0) && (i==size-1||arr[i+1]==0)){
                arr[i]=1;
                n--;
            }
        }
        if(n<=0){
            return true;
        }
        return false;
    }
};