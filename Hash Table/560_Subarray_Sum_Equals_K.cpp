//Given an array of integersand an integer k, you need to find the total number of continuous subarrays whose sum equals to k.
//
//Example 1:
//
//Input:nums = [1, 1, 1], k = 2
//Output : 2



//若Hash table裡面有sum-k的值,代表一定有subarray的和為k
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0, sum = 0;
        unordered_map<int, int> m{ {0,1} };
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            res += m[sum - k];
            m[sum]++;
        }
        return res;
    }
};