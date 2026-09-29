// class Solution {
// public:
//     int  countways(int n, int curr){
//         //base case
//         if(curr==n){
//             return 1;
//         }
//         if(curr>n){
//             return 0;
//         }
//         return countways(n,curr+1)+countways(n,curr+2);
//     }
//      int climbStairs(int n) {
//         int curr=0;
//         int ans=countways( n,curr);
//         return ans;
//     }
// };



class Solution {
public:
    int climbStairs(int n) {

        int a = 1;
        int b = 1;

        for (int i = 2; i <= n; i++) {
            int c = a + b;

            a = b;
            b = c;
        }

        return b;
    }
};
        