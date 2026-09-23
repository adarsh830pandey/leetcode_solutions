// class Solution {
// public:
//     void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // int i = m - 1;       // last actual element of nums1
        // int j = n - 1;       // last element of nums2
        // int k = m + n - 1;   // last position of nums1
        // while (i >= 0 && j >= 0) {
        //     if (nums1[i] > nums2[j]) {
        //         nums1[k] = nums1[i];
        //         i--;
        //     }
        //     else {
        //         nums1[k] = nums2[j];
        //         j--;
        //     }
        //     k--;
        // }
        // // If nums2 still has elements
        // while (j >= 0) {
        //     nums1[k] = nums2[j];
        //     j--;
        //     k--;
        // }

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        vector<int> ans;

        int i = 0;  // nums1
        int j = 0;  // nums2

        while (i < m && j < n) {

            if (nums1[i] < nums2[j]) {
                ans.push_back(nums1[i]);
                i++;
            }
            else {
                ans.push_back(nums2[j]);
                j++;
            }
        }

        // Remaining elements of nums1
        while (i < m) {
            ans.push_back(nums1[i]);
            i++;
        }

        // Remaining elements of nums2
        while (j < n) {
            ans.push_back(nums2[j]);
            j++;
        }

        // Copy ans into nums1
        for (int k = 0; k < m + n; k++) {
            nums1[k] = ans[k];
        }
    }
};