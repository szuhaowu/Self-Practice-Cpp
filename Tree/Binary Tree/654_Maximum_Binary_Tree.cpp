// Given an integer array with no duplicates. A maximum tree building on this array is defined as follow:

// The root is the maximum number in the array.
// The left subtree is the maximum tree constructed from left part subarray divided by the maximum number.
// The right subtree is the maximum tree constructed from right part subarray divided by the maximum number.
// Construct the maximum tree by the given array and output the root node of this tree.

// Example 1:
// Input: [3,2,1,6,0,5]
// Output: return the tree root node representing the following tree:

//       6
//     /   \
//    3     5
//     \    / 
//      2  0   
//        \
//         1


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        //建立新的function以便我們記住檢索位置
        return build(nums,0,nums.size()-1);
    }
    TreeNode* build(vector<int>& nums,int left,int right){
        if(left>right) return nullptr;
        int maxVal = INT_MIN, index = 0;
        for(int i=left; i<=right; i++) { 
            if(maxVal<nums[i]){
                maxVal = nums[i];
                index = i;
            }
        }
        TreeNode* node = new TreeNode(maxVal);
        node->left = build(nums,left,index-1);
        node->right = build(nums,index+1,right);
        return node;
    }
};