//Given an array nums of n integers where n > 1, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].
//
//Example:
//
//Input: [1, 2, 3, 4]
//Output : [24, 12, 8, 6]
//Constraint : It's guaranteed that the product of the elements of any prefix or suffix of the array (including the whole array) fits in a 32 bit integer.
//
//Note : Please solve it without division and in O(n).

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        //seperate array as the left product of nums[i] and right product of nums[i]
        //left product time right product is result
        int n = nums.size();
        vector<int> res(n, 1);
        for (int i = 0; i < n - 1; i++) {
            res[i + 1] = res[i] * nums[i];
        }
        int right = 1;
        for (int i = n - 1; i >= 0; i--) {
            res[i] = res[i] * right;
            right = right * nums[i];
        }
        return res;
    }
};