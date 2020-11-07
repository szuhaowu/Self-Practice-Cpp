//Given preorder and inorder traversal of a tree, construct the binary tree.
//
//Note:
//You may assume that duplicates do not exist in the tree.
//
//For example, given
//
//preorder = [3,9,20,15,7]
//inorder = [9,3,15,20,7]
//Return the following binary tree:
//
//    3
//   / \
//  9  20
//    /  \
//   15   7

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//related to 106
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildNode(inorder, 0, inorder.size() - 1, preorder, 0, preorder.size() - 1);
    }

    TreeNode* buildNode(vector<int>& inorder, int iLeft, int iRight, vector<int>& preorder, int pLeft, int pRight) {
        if (iLeft > iRight || pLeft > pRight) return NULL;
        TreeNode* new_node = new TreeNode(preorder[pLeft]);
        int i = 0;
        for (i = iLeft; i < inorder.size(); i++) {
            if (inorder[i] == preorder[pLeft]) break;
        }
        new_node->left = buildNode(inorder, iLeft, i - 1, preorder, pLeft + 1, pLeft + i - iLeft);
        new_node->right = buildNode(inorder, i + 1, iRight, preorder, pLeft + i - iLeft + 1, pRight);

        return new_node;

    }
};