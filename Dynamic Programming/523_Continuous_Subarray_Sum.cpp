//Given a list of non-negative numbers and a target integer k, write a function to check if the array has a continuous subarray of size at least 2 that sums up to a multiple of k,
// that is, sums up to n*k where n is also an integer.
//
// 
//
//Example 1:
//
//Input: [23, 2, 4, 6, 7],  k=6
//Output: True
//Explanation: Because [2, 4] is a continuous subarray of size 2 and sums up to 6.
//Example 2:
//
//Input: [23, 2, 6, 4, 7],  k=6
//Output: True
//Explanation: Because [23, 2, 6, 4, 7] is an continuous subarray of size 5 and sums up to 42.
// 
//
//Constraints:
//
//The length of the array won't exceed 10,000.
//You may assume the sum of all the numbers is in the range of a signed 32-bit integer.


//若a%c與 b%c相等 則a-b被c整除
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size(), sum = 0, pre = 0;
        unordered_set<int> st;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            int t = (k == 0) ? sum : (sum % k);
            if (st.count(t)) return true;
            st.insert(pre);
            pre = t;
        }
        return false;
    }
};
