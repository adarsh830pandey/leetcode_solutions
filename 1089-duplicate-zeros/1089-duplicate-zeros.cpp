class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n=arr.size();
        vector<int>temp;
        for(int i=0; i<n; i++){
            int elem=arr[i];
            if(elem==0){
                temp.push_back(0);
            }
            temp.push_back(arr[i]);
           

        }
        for(int i=0; i<arr.size(); i++){
            arr[i]=temp[i];
        }

       
        
    }
};