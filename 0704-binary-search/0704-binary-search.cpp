// class Solution {
// public:
//     int search(vector<int>& nums, int target) {
//          int n=nums.size();
//          int s=0;
//          int e=n-1;
//          int mid=(s+e)/2;
//          while(s<=e){
//             if (nums[mid]==target){
//                 return mid;
//             }
//             else if(nums[mid]<target){
//                 s=mid+1;
//             }
//             else if(nums[mid]>target){
//                 e=mid-1;
//             }
//             mid=(s+e)/2;

//          }
//       return -1;
//     }
// };

class Solution {
public:
    int binarySearch(vector<int>& nums, int s, int e, int target) {

        // Base case
        if (s > e) {
            return -1;
        }
       int mid = s + (e - s) / 2;
        // Target found
        if (nums[mid] == target) {
            return mid;
        }
        // Search in right half
        else if (nums[mid] < target) {
            return binarySearch(nums, mid + 1, e, target);
        }

        // Search in left half
        else {
            return binarySearch(nums, s, mid - 1, target);
        }
    }
     int search(vector<int>& nums, int target) {
        int s = 0;
        int e = nums.size() - 1;
        return binarySearch(nums, s, e, target);
    }
};