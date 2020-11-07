//Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.
//
//Example:
//Given a binary tree
//          1
//         / \
//        2   3
//       / \     
//      4   5    
//Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].
//
//Note: The length of path between two nodes is represented by the number of edges between them.

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


//用Hash Table記住當前node的res就可以不用一直重新找
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        maxDep(root, res);
        return res;
    }

    int maxDep(TreeNode* node, int& res) {
        if (!node) return 0;
        if (m.count(node)) return m[node];
        int left = maxDep(node->left, res);
        int right = maxDep(node->right, res);
        res = max(res, left + right);
        return m[node] = (max(left, right) + 1);
    }

private:
    unordered_map<TreeNode*, int> m;
};