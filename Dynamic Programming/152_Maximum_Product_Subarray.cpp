//Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.
//
//Example 1:
//
//Input: [2,3,-2,4]
//Output: 6
//Explanation: [2,3] has the largest product 6.
//Example 2:
//
//Input: [-2,0,-1]
//Output: 0
//Explanation: The result cannot be 2, because [-2,-1] is not a subarray.

//最大值一定在 nums[i], nums[i]*maximum[i-1], nums[i]*minimum[i-1] 之中, 用兩個dp來記錄最大與最小值
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0];
        vector<int> maximum(nums.size(), 0), minimum(nums.size(), 0);
        maximum[0] = nums[0];
        minimum[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            maximum[i] = max(nums[i], max(nums[i] * maximum[i - 1], nums[i] * minimum[i - 1]));
            minimum[i] = min(nums[i], min(nums[i] * maximum[i - 1], nums[i] * minimum[i - 1]));
            res = max(res, maximum[i]);
        }
        return res;
    }
};