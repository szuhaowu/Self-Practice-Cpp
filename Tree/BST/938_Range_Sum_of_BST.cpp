//Given the root node of a binary search tree, return the sum of values of all nodes with value between L and R (inclusive).
//
//The binary search tree is guaranteed to have unique values.
//
// 
//
//Example 1:
//
//Input: root = [10,5,15,3,7,null,18], L = 7, R = 15
//Output: 32
//Example 2:
//
//Input: root = [10,5,15,3,7,13,18,1,null,6], L = 6, R = 10
//Output: 23


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
    int rangeSumBST(TreeNode* root, int L, int R) {
        if (!root) return 0;
        if (root->val < L) return rangeSumBST(root->right, L, R);
        if (root->val > R) return rangeSumBST(root->left, L, R);
        return root->val + rangeSumBST(root->left, L, R) + rangeSumBST(root->right, L, R);
    }
};